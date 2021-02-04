#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n, m, x;
	unordered_map<int, int> ma;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		ma[x]++;
	}
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> x;
		if (ma[x]) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
	return 0;
}
