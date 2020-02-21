#include <iostream>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[101][101] = { 0, };
int visit[101][101] = { 0, };

int n, m, k;
int cnt = 0;
int trash_max = 0;

void dfs(int i, int j) {
	for (int b = 0; b < 4; b++) {
		visit[i][j] = 1;
		int next_i = i + dx[b];
		int next_j = j + dy[b];
		if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m) {
			if (arr[next_i][next_j] == 1 && visit[next_i][next_j] == 0) {
				cnt++;
				dfs(next_i, next_j);
			}
		}
	}
}



int main() {
	int x, y;
	cin >> n >> m >> k;
	for (int a = 0; a < k; a++) {
		cin >> x >> y;
		arr[x-1][y-1] = 1;
	}
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < m; d++) {
			if (arr[c][d] == 1 && visit[c][d]==0) {
				cnt = 1;
				dfs(c,d);
				if (cnt > trash_max) trash_max = cnt;
			}
		}
	}
	cout << trash_max << "\n";
	system("pause");
	return 0;
}