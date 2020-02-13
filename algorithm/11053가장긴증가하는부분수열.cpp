#include <iostream>
using namespace std;

int arr[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
	int N;
	int max_lenght = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > max_lenght) max_lenght = dp[i];
	}
	cout << max_lenght << "\n";
	system("pause");
	return 0;
}