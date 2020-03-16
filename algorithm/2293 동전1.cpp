#include <iostream>
using namespace std;

int dp[10001] = { 0, };
int coin[101] = { 0, };

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int j = 1; j <= n; j++) {
		for (int l = coin[j]; l <= k; l++) {
			dp[l] = dp[l] + dp[l - coin[j]];
		}
	}
	cout << dp[k] << "\n";
	system("pause");
	return 0;
}