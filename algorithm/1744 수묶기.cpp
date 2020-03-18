#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001] = { 0, };

int main() {
	//음수*음수, 1은 무조건 넘어간다, 음수*0, 양수*양수
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int left = 0;
	int right = n - 1;
	//음수일 때
	for (; left < n - 1; left++) {
		if (arr[left] <= 0 && arr[left + 1] <= 0) {
			res += arr[left] * arr[left + 1];
			left++;
		}
		else {
			break;
		}
	}
	//1보다 큰 양수일 때
	for (; right >= left + 1; right--) {
		if (arr[right] > 1 && arr[right - 1] > 1) {
			res += arr[right] * arr[right - 1];
			right--;
		}
		else {
			break;
		}
	}
	for (; left <= right; left++) {
		res += arr[left];
	}
	cout << res << "\n";
	system("pause");
	return 0;
}