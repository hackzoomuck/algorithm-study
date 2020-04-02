#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> c) {
	string s = "";
	for (int j = 0; j < c.size()-1; j++) {
		if (c[j] < c[j + 1]) {
			if (s=="plus") return false;
			s = "plus";
		}
		else if (c[j] > c[j + 1]) {
			if (s=="minus") return false;
			s = "minus";
		}
		else false;
	}
	return true;
}

int solution(vector<int> &A) {
	int cnt = 0;
	if (check(A)) return 0;
	for (int i = 0; i < A.size(); i++) {
		vector<int> tmp = A;
		tmp.erase(tmp.begin()+i);
		if(check(tmp)){
			cnt++;
		}
	}
	cout << cnt;
	if (cnt) return cnt;
	return -1;
}

int main() {
	vector<int> v;
	v = { 3,4,5,3,7 };
	solution(v);
	system("pause");

	return 0;
}