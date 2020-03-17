#include <iostream>
using namespace std;

long long dp[101][10] = { 0, };

int main() {
	int n;
	long long res = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int j = 2; j <= n; j++) {
		dp[j][0] = dp[j - 1][1];
		dp[j][9] = dp[j - 1][8];
		for (int k = 1; k <= 8; k++) {
			dp[j][k] = (dp[j - 1][k - 1] + dp[j - 1][k + 1]) % 1000000000;
		}
	}
	for (int l = 0; l <= 9; l++) {
		res += dp[n][l];
	}
	cout << res % 1000000000 << "\n";
	return 0;
}
