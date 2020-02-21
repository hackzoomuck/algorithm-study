#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f

int arr[101][101] = { 0, };

int main() {
	int n, m, a, b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	int min_sum = INF;
	int min_num = 0;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = 1; j <= n; j++) {
			cur += arr[i][j];
		}
		if (min_sum > cur) {
			min_sum = cur;
			min_num = i;
		}
	}
	cout << min_num << "\n";
	system("pause");
	return 0;
}