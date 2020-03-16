#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000] = { 0, };
int coin[101] = { 0, };

int main() {
	int n, k;
	cin >> n >> k;
	for (int a = 1; a <= n; a++) {
		cin >> coin[a];
	}
	for (int b = 1; b <= k; b++) {
		dp[b] = 100000;
	}
	for (int i = 1; i <= n; i++) {
		dp[coin[i]] = 1;
		for (int j = coin[i]+1; j <= k; j++) {
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
		}
	}
	if (dp[k] == 100000) {
		cout << "-1\n";
		return 0;
	}
	cout << dp[k] << "\n";
	system("pause");

	return 0;
}