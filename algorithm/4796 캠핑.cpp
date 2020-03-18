#include <iostream>
using namespace std;

int main() {
	int l, p, v, i = 1;

	cin >> l >> p >> v;
	while (l || p || v) {
		int a = (v / p)*l;
		int b = v % p;
		if (b > l)b = l;
		cout << "Case " << i << ": " << a + b << "\n";
		i++;
		cin >> l >> p >> v;
	}
	system("pause");
	return 0;
}
