#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


int solution(vector<int> &A) {
	vector<vector<int>> v;
	set<int> s;
	v.resize(200001);
	int max_sum = 0;
	for (int i = 0; i < A.size(); i++) {
		int num = A[i];
		int sum = 0;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		v[sum].push_back(A[i]);
		s.insert(sum);
	}
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); ++it) {
		int is = *it;
		if (v[is].size() >= 2) {
			sort(v[is].rbegin(), v[is].rend());
			if (max_sum < v[is][0] + v[is][1]) {
				max_sum = v[is][0] + v[is][1];
			}
		}
	}
	cout << max_sum;
	if (max_sum) return max_sum;
	return -1;
}

int main() {
	vector<int> vv;
	vv = { 51,32, 43 };
	solution(vv);
	system("pause");
	return 0;
}