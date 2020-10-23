#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

int N = 0, K = 0;//N:입력숫자, K:몇 번째

int rotation() {
	string input = "";
	long long answer = 0;
	int num_size = N / 4;
	map<string, int>m;
	vector<string>v;

	cin >> input;
	for (int i = 0; i < num_size; i++) {
		if (i) {
			string s1 = input.substr(0, N - 1);
			string s2 = input.substr(N - 1);
			input = s2 + s1;
		}
		for (int j = 0; j < 4; j++) {
			string s3 = input.substr(j * num_size, num_size);
			if (!m[s3]) {
				m[s3]++;
				v.push_back(s3);
			}
		}
	}
	if (v.size() >= K) {
		sort(v.rbegin(), v.rend());
		for (int l = 0; l < v[K - 1].size(); l++) {
			int cha_n = v[K - 1][l] - 'A';
			if (cha_n < 0) {
				cha_n = v[K - 1][l] - '0';
			}
			else {
				cha_n += 10;
			}
			answer += cha_n * pow(16, num_size - l - 1);
		}
		return answer;
	}
}

int main() {
	int testcase = 0;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t) {
		cin >> N >> K;
		cout << "#" << t << " " << rotation()<<"\n";
	}
	return 0;
}