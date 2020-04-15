#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][2] = { 0, };
int dx[4] = { -2,-1,1,2 };

int fuc(int width) {
	int cnt = 0;
	for (int f1 = 2; f1 < width - 2; f1++) {
		if (arr[f1][0] < arr[f1][1]) continue;

		for (int f2 = 0; f2 < 4; f2++) {
			if (arr[f1][0] < arr[f1 + dx[f2]][0]) break;
			else {
				arr[f1][1] = max(arr[f1][1], arr[f1 - dx[f2]][0]);
				arr[f1 + dx[f2]][1] = max(arr[f1 + dx[f2]][1], arr[f1][0]);
			}

			if(f2 == 3) cnt += arr[f1][0] - arr[f1][1];

		}
	}

	return cnt;
}

int main() {
	for (int test = 1; test <= 10; test++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0];
			arr[i][1] = 0;
		}
		cout << "#" << test << " " << fuc(n) <<"\n";
	}

	return 0;
}