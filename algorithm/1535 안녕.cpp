#include <iostream>
#include <algorithm>
using namespace std;

int dp[101] = { 0, };
int hp[101] = { 0, };
int happy[101] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hp[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> happy[j];
	}
	for (int k = 0; k < n; k++) {
		for (int ht = 100; ht >= hp[k]; ht--) {
			dp[ht] = max(dp[ht], dp[ht - hp[k]] + happy[k]);
		}
	}
	cout << dp[99] << "\n";
	system("pause");

	return 0;
}
