#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < participant.size(); i++) {
		if (!completion.size()) {
			answer = participant[i];
			return answer;
		}
		bool check = false;
		int left = 0;
		int right = completion.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (participant[i] == completion[mid]) {
				completion.erase(completion.begin() + mid);
				check = true;
				break;
			}
			else {
				if (participant[i][0] < completion[mid][0]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
		if (!check) {
			answer = participant[i];
			return answer;
		}
	}
}

void main() {
	vector<string> p;
	vector<string> c;
	p.push_back("le");
	p.push_back("ki");
	p.push_back("ed");
	c.push_back("ed");
	c.push_back("ki");
	solution(p, c);
}