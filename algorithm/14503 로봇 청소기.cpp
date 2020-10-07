#include <iostream>
using namespace std;

int n, m;
int romap[51][51]; //0-û���ʿ� 1-�� 2-û�ҵ�
int answer = 0; //û���� ����


// 0:�� 1:�� 2:�� 3:��
int bx[4] = { 1,0,-1,0 };
int by[4] = { 0,1,0,-1 };


// 0:�� 1:�� 2:�� 3:�� : left
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

// rear �� �� �� ��
int rx[4] = { -1,0,1,0 };
int ry[4] = { 0,-1,0,1 };

int d[4] = { 3,2,1,0 };

struct {
	int r, c, dir;
	int dcnt = 0; //ȸ�� �� 
}robo;

void dfs() {
	if (romap[robo.r][robo.c] == 0) {
		romap[robo.r][robo.c] = 2;
		answer++;
	}
	robo.dcnt = 0;
	for (int i = 0; i < 4; i++) {
		//���� ����
		int nx = robo.r + dx[robo.dir];
		int ny = robo.c + dy[robo.dir];

		//���� ���⿡ û���� �� ������
		if (romap[nx][ny] == 0) {
			//���� �ٲٱ�
			robo.dir = d[robo.dir];
			//�� ĭ �̵�
			robo.r = nx;
			robo.c = ny;
			dfs();
			return;
		}
		else { //���� ���⿡ û���� �� ������
			//���� �ٲٱ�
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