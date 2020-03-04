#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	for (int j = 1; j < n; j++) {
		arr[j][0] += min(arr[j - 1][1], arr[j - 1][2]);
		arr[j][1] += min(arr[j - 1][0], arr[j - 1][2]);
		arr[j][2] += min(arr[j - 1][0], arr[j - 1][1]);
	}
	int min_cost = min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2]));
	cout << min_cost << "\n";
	system("pause");
	return 0;
}