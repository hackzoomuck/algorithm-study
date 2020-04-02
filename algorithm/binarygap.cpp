#include <iostream>
#include <string>
using namespace std;


int solution(int N) {
	int n = N;
	int binary = 0;
	string s = "";
	for (; n > 0;) {
		s.append(to_string(n % 2));
		n = n / 2;
	}
	int length_max = 0;
	int length_now = 0;
	bool one_check = false;
	for (int j = 0; j < s.size(); j++) {
		if (s[j] == '1') {
			one_check = true;
			if (length_max < length_now) {
				length_max = length_now;
			}
			length_now = 0;
		}
		if (one_check && s[j] == '0') length_now++;
	}
	return length_max;
}

int main() {
	cout << solution(8);
	system("pause");
	return 0;
}