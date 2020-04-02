#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int rest_cnt = 0;//°¡´ÉÇÑ ½°Ç¥°¹¼ö
	for (int i = 1; i < s.size() - 1; i++) {
		int left = 0;
		int right = 0;
		if (s[i] == ','&& s[i - 1] == '{') {
			s.erase(i, 1);
		}
		int cnt = 0;//Æ©ÇÃ½°Ç¥°¹¼ö
		if (s[i] == '{') {
			left = i;
			i++;
			while (s[i] != '}') {
				if (s[i] == ',') cnt++;
				i++;
			}
		}
		if (s[i] == '}') {
			right = i;
			if (cnt == rest_cnt) {
				string tmp_s = "";
				bool check = true;//answer¿¡ °°Àº °ª ¾øÀ½.
				for (int j = left + 1; j < right; j++) {
					check = true;
					if (s[j] != ',') {
						tmp_s.append(1, s[j]);
					}
					if (s[j] == ',') {

						for (int k = 0; k < answer.size(); k++) {
							if (answer[k] == stoi(tmp_s)) {
								check = false;
								break;
							}
						}
						if (check) {
							answer.push_back(stoi(tmp_s));
						}
						tmp_s = "";
					}
				}
				for (int k = 0; k < answer.size(); k++) {
					if (answer[k] == stoi(tmp_s)) {
						check = false;
						break;
					}
				}
				if (check) {
					answer.push_back(stoi(tmp_s));
					tmp_s = "";
				}
				rest_cnt++;
				if (s[left - 1] == ',') {
					s.erase(left - 1, right - left + 2);
				}
				else {
					s.erase(left, right - left + 1);
				}
				i = 0;
			}
		}
	}

	for (int l = 0; l < answer.size(); l++) {
		cout << answer[l] << " ";
	}
	return answer;
}

int main() {
	string input = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
	solution(input);
	system("pause");
	return 0;
}
