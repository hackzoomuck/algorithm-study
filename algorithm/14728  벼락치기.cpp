#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001] = { 0, };

int main() {
	int n, t, k, s;
	cin >> n >> t;
	while (n--) {
		cin >> k >> s;
		for (int i = t; i >= k; i--) {
			dp[i] = max(dp[i], dp[i - k] + s);
		}
	}
	cout << dp[t] << "\n";
	return 0;
}