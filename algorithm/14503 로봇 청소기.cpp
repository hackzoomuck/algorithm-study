#include <iostream>
using namespace std;

int n, m;
int romap[51][51]; //0-청소필요 1-벽 2-청소됨
int answer = 0; //청소한 구역


// 0:북 1:동 2:남 3:서
int bx[4] = { 1,0,-1,0 };
int by[4] = { 0,1,0,-1 };


// 0:서 1:남 2:동 3:북 : left
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

// rear 남 서 북 동
int rx[4] = { -1,0,1,0 };
int ry[4] = { 0,-1,0,1 };

int d[4] = { 3,2,1,0 };

struct {
	int r, c, dir;
	int dcnt = 0; //회전 수 
}robo;

void dfs() {
	if (romap[robo.r][robo.c] == 0) {
		romap[robo.r][robo.c] = 2;
		answer++;
	}
	robo.dcnt = 0;
	for (int i = 0; i < 4; i++) {
		//왼쪽 방향
		int nx = robo.r + dx[robo.dir];
		int ny = robo.c + dy[robo.dir];

		//왼쪽 방향에 청소할 곳 있으면
		if (romap[nx][ny] == 0) {
			//방향 바꾸기
			robo.dir = d[robo.dir];
			//한 칸 이동
			robo.r = nx;
			robo.c = ny;
			dfs();
			return;
		}
		else { //왼쪽 방향에 청소할 곳 없으면
			//방향 바꾸기
			robo.dir = d[robo.dir];
			robo.dcnt++;
		}
	}
	if (robo.dcnt == 4) {
		int nx = robo.r + rx[robo.dir];
		int ny = robo.c + ry[robo.dir];
		if (romap[nx][ny] == 1) return;
		else {
			robo.r = nx;
			robo.c = ny;
			dfs();
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> robo.r >> robo.c >> robo.dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> romap[i][j];
		}
	}

	dfs();
	cout << answer;
	
	system("pause");
	return 0;
}