#include <iostream>
using namespace std;

int n, m;
int romap[51][51]; //0-청소필요 1-벽 2-청소됨
int answer = 0; //청소한 구역


// 0:북 1:동 2:남 3:서 <= 그때 정신이 나갔었나보다.
int bx[4] = { -1,0,1,0 };
int by[4] = { 0,1,0,-1 };

// rear 남 서 북 동
int rx[4] = { 1,0,-1,0 };
int ry[4] = { 0,-1,0,1 };

int d[4] = { 3,0,1,2 };

struct {
	int r, c, dir;
}robo;

void dfs() {
    while(1){
	if (romap[robo.r][robo.c] == 0) {
		romap[robo.r][robo.c] = 2;
		answer++;
	}
	bool check = false;
	for (int i = 0; i < 4; i++) {
		//왼쪽 방향
		int nx = robo.r + bx[d[robo.dir]];
		int ny = robo.c + by[d[robo.dir]];
		
		if(nx<=0||ny<=0||nx>=n-1||ny>=m-1){
                	robo.dir = d[robo.dir];
                	continue;
            	}

		//왼쪽 방향에 청소할 곳 있으면
		if (romap[nx][ny] == 0) {
			//방향 바꾸기
			robo.dir = d[robo.dir];
			//한 칸 이동
			robo.r = nx;
			robo.c = ny;
			check = true;
                	break;
		}
		else { //왼쪽 방향에 청소할 곳 없으면
			//방향 바꾸기
			robo.dir = d[robo.dir];
		}
	}
	if (!check) {
		int nx = robo.r + rx[robo.dir];
		int ny = robo.c + ry[robo.dir];
		if (romap[nx][ny] == 1) return;
		else {
			robo.r = nx;
			robo.c = ny;
		}
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
