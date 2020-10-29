#include <iostream>
#include <vector>
using namespace std;

int arr[501][501] = { 0, };
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N = 0;
int per[10] = { 5,10,10,7,7,2,2,1,1 };
int sxp[5][10] = { {0,-1,1,-1,1,-2,2,-1,1},{2,1,1,0,0,0,0,-1,-1},{0,-1,1,-1,1,-2,2,-1,1},{-2,-1,-1,0,0,0,0,1,1}, };
int syp[5][10] = { {-2,-1,-1,0,0,0,0,1,1},{0,-1,1,-1,1,-2,2,-1,1},{2,1,1,0,0,0,0,-1,-1},{0,-1,1,-1,1,-2,2,-1,1}, };


void push_sand(int d, int px, int py) {
	int cursand = arr[px][py];
	if (cursand < 10) {
		if (px >= 0 && px < N&&py >= 0 && py < N) {
			arr[px + dx[d]][py + dy[d]] += cursand;
		}
		else {
			for (int i = 0; i < 9; i++) {
				int npx = px + sxp[d][i];
				int npy = py + syp[d][i];
				if (npx < 0 || npx >= N || npy < 0 || npy >= N) continue;
				else {
					arr[npx][npy] += cursand * per[i] / 100;
				}
			}
			//rest sand for a%
			//out of range
			if (px + dx[d] >= 0 && px + dx[d] < N && py + dy[d] >= 0 && py + dy[d] < N){
				int smove = cursand * 0.45;
				arr[px + dx[d]][py + dy[d]] += cursand - smove;
			}
			arr[px][py] = 0;
		}
	}	
}

int rota() {
	int map_sand = 0;
	int x = (N - 1) / 2;
	int y = (N - 1) / 2;
	int dir = 0;
	for (int rc = 1; rc < N-1; rc++) {
		for (int two = 0; two < 2; two++) {
			for (int dirc = 0; dirc < rc; dirc++) {
				x += dx[dir];
				y += dy[dir];
				push_sand(dir, x, y);
			}
		}
		dir = (dir + 1) % 4;
	}
	for (int lc = 0; lc < N-1; lc++) {
		x += dx[0];
		y += y + dy[0];
		push_sand(0, x, y);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map_sand += arr[i][j];
		}
	}
	cout << map_sand << "\n";
	return map_sand;
}

int  init_arr() {
	int total_sand = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			total_sand += arr[i][j];
		}
	}
	cout << total_sand << "\n";
	return total_sand;
}

int main() {
	cin >> N;
	int pre_sand = init_arr();
	int end_sand = rota();
	cout << pre_sand - end_sand;
	system("pause");
	return 0;
}