#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int main() {
	int n, x, y;
	cin >> n;
	//  그냥 다 비교할 것이다.
	for (int a = 0; a < n; a++) {
		cin >> x >>  y;
		v.push_back({ x,y });
	}
	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second) rank++;
		}
		cout << rank << " ";
	}
	return 0;
}
