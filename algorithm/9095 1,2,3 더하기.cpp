#include <iostream>
using namespace std;

int arr[11] = { 0, };

int main() { 
	int n, input;
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 10; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < n; i++) {
		cin >> input;
		cout << arr[input] << "\n";
	}
	system("pause");
	return 0;
}
