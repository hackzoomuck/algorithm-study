#include <iostream>
#include <vector>
using namespace std;

int n, m;
int r, c, dir;
vector<vector<int>> v; //0-청소필요 1-벽 2-청소됨
int answer = 0;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int bx[4] = { 1,0,-1,1 };
int by[4] = { 0,-1,0,1 };




//return 0 는 작동을 멈출조건
void dfs(int x, int y, int d) {
	if (v[x][y] == 1) {
		return;
	}
	if (v[x][y]==0) {
		v[x][y] = 2;
		answer++;
	}
	for (int i = d; i > d-4 ; i--) {
		int nx = x + dx[(i + 4) % 4];
		int ny = y + dy[(i + 4) % 4];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (v[nx][ny] == 0) {
				dfs(nx, ny, (i + 3) % 4);
				return ;
			}

		}
	}
	int bnx = x + bx[d];
	int bny = y + by[d];
	/*if (bnx >= 0 && bnx < n && bny >= 0 && bny < m) {
		if (v[bnx][bny] == 2) {
			dfs(bnx, bny, d);
		}
	}*/
	dfs(bnx, bny, d);

	/*return 0;
*/
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> dir;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		vector<int> vy;
		vy.resize(m);
		for (int j = 0; j < m; j++) {
			cin >> vy[j];
		}
		v[i] = vy;
	}

	dfs(r, c, dir);
	cout << answer;
	
	system("pause");
	return 0;
}