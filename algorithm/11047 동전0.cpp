#include <iostream>
#include <algorithm>
using namespace std;

int arr[11] = { 0, };
bool desc(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, desc);
	int cur = k;
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		if (cur == 0) break;
		if (cur >= arr[j]) {
			cnt += cur / arr[j];
			cur = cur % arr[j];
		}
	}
	cout << cnt << "\n";
	system("pause");
	return 0;
}