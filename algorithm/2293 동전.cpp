#include <iostream>
using namespace std;

int coin[101] = { 0, };
int dp[10001] = { 0, };

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int a = 1; a <= n; a++) {
		for (int b = coin[a]; b <= k; b++) {
			dp[b] = dp[b] + dp[b - coin[a]];
		}
	}
	cout << dp[k] << "\n";
	system("pause");
	return 0;
}
