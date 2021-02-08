#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {
	int n;
	string s;
	vector<string> vs;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (find(vs.begin(), vs.end(), s) == vs.end()) {
			vs.push_back(s);
		}	
	}
	sort(vs.begin(), vs.end(), cmp);
	for (int i = 0; i < vs.size(); i++) {
			cout << vs[i] << "\n";
	}
	return 0;
}
