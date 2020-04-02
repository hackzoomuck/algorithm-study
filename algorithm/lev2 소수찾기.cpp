#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[10000001] = { 0, };
bool upnum(char a, char b) {
	return a > b;
}

void go(int end_num) {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i*i <= end_num; i++) {
		if (arr[i]) continue;
		for (int j = i + i; j <= end_num; j += i) {
			arr[j] = 1;
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), upnum);
	int max_num = stoi(numbers);
	go(max_num);

	for (int i = 2; i <= max_num; i++) {
		if (!arr[i]) {
			string s = numbers;
			string checks = to_string(i);
			int checki = checks.size();
			for (int a = 0; a < checks.size(); a++) {
				for (int b = 0; b < s.size(); b++) {
					if (checks[a] == s[b]) {
						checki--;
						s.erase(b, 1);
						break;//에러: break가 없어서 중복된 것을 지워버리기에 에러남.
					}
				}
			}
			if (checki == 0) {
				answer++;
			}
		}
	}
	cout << answer;
	return answer;
}

int main() {
	string s = "013";
	sort(s.begin(), s.end(), upnum);
	cout << s << endl;
	solution(s);
	system("pause");

	return 0;
}
