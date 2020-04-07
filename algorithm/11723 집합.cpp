#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n;
	unsigned int input = 0;
	string s;
	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "add") {
			cin >> n;
			input |= (1 << n);
		}
		else if (s[0] == 'r') {
			cin >> n;
			input &= ~(1 << n);
		}
		else if (s[0] == 'c') {
			cin >> n;
			if (input & (1 << n)) cout << "1\n";
			else cout << "0\n";
		}
		else if (s[0] == 't') {
			cin >> n;
			//xor 0^0 =0/1^0=1/0^1=1/1^1=0
			input ^= (1 << n);
		}
		else if (s == "all") {
			input = (1 << 21) - 1;
		}
		else {
			input = 0;
		}
	}

	return 0;
}
