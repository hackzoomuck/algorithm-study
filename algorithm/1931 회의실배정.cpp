#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, s, e, cnt=0, end_time=0;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n-1; i++) {
		//�ٷ� �ڿ����̶� ���ؼ� ������ �ð��� �� ������ ������ ���.
		if (end_time <= v[i].first) {
			if (v[i].second > v[i + 1].second) continue;
			else {
				cnt++;
				end_time = v[i].second;
			}
		}
	}
	if (end_time <= v[n - 1].first) cnt++;
	cout << cnt << "\n";
	system("pause");
	return 0;
}