#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int solution(vector<int> &A) {
	sort(A.rbegin(), A.rend());
	unordered_map<int, int>m;
	for (int i = 0; i < A.size(); i++) {
		m[(A[i])*(-1)]++;
	}
	unordered_map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		if ((it->first)*(-1) == it->second) {
			return it->second;
		}
	}
	cout << "0";
	return 0;
}

int main() {
	vector<int> v;
	v = { 3, 8, 2, 3, 3, 2 };
	solution(v);
	system("pause");
	return 0;
}