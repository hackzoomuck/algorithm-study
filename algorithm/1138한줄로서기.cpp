#include <iostream>
using namespace std;

int arr[10] = { 0, };

int main() {
	int n, left;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> left;
		for (int j = 0; j < n; j++) {
			if (left == 0 && arr[j] == 0) {
				arr[j] = i+1;
				break;
			}
			else if (arr[j] == 0) {
				left--;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		cout << arr[k] << " ";
	}
	cout << "\n";
	system("pause");
	return 0;  
}