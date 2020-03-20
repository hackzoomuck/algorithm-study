#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t, n, a, b;
	cin >> t;
	vector<pair<int, int>> v;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());

		int highscore = v[0].second;
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (highscore > v[j].second) {
				highscore = v[j].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
		v.clear();
	}
	return 0;
}
