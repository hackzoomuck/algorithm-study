#include <iostream>
using namespace std;

int coin[6] = { 500,100,50,10,5,1 };

int main() {
	int pay, cnt=0, index=0;
	cin >> pay;
	int charge = 1000 - pay;

	while (charge) {
		if (charge - coin[index] >= 0) {
			charge -= coin[index];
			cnt++;
		}
		else {
			index++;
		}
	}
	cout << cnt << "\n";
	system("pause");
	return 0;
}