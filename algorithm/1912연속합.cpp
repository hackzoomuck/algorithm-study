#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001] = { 0, };
int max_res = -1000;

int main() {
	int n, num;
	cin >> n >> num;
	dp[0] = num;
	if (dp[0] > max_res) max_res = dp[0];
	for (int i = 1; i < n; i++) {
		cin >> num;
		dp[i] = max(dp[i - 1] + num, num);
		if (dp[i] > max_res) max_res = dp[i];
	}
	cout << max_res << "\n";
	system("pause");
	return 0;
}