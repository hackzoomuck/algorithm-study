#include <iostream>
using namespace std;

int n;
double per[4];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
double total_per = 0;
int m[28][28] = { 0, };
void dfs(int x, int y, int cur, double p) {
	if (cur == n) {
		total_per += p;
		return;
	}
	m[x][y] = 1;
	int mx, my;
	for (int i = 0; i < 4; i++) {
		mx = x + dx[i];
		my = y + dy[i];
		if (m[mx][my] == 0) {
			p *= per[i];
			dfs(mx, my, cur + 1, p);
		}
		else {
			p *= 0;
		}
	}
	m[x][y] = 0;
}

int main() {
	cin >> n;
	double m;
	for (int i = 0; i < 4; i++) {
		cin >> m;
		per[i] = m / 100;
	}
	dfs(n, n, 0, 1);
	cout << total_per;
	system("pause");
	return 0;
}