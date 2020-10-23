#include <stdio.h>
#include <iostream>
using namespace std;

int arr[9][9] = { 0, };
int visit[9][9] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int max_height_result = 0;
int N, K;

void dfs(int x, int y, int cnt) {
	visit[x][y] = true;
	cnt++;
	if (max_height_result < cnt) {
		max_height_result = cnt;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny] || nx < 0 || ny < 0 || N <= nx || N <= ny) continue;
		if (arr[nx][ny] < arr[x][y]) {
			dfs(nx, ny, cnt);
			visit[nx][ny] = false;
		}
	}
}

void find_maxbong() {
	int max_h = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max_h < arr[i][j]) {
				max_h = arr[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == max_h) {
				dfs(i, j, 0);
				memset(visit, 0, sizeof(visit));
			}
		}
	}
}

void dig() {
	for (int a = 1; a <= 5; a++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] -= a;
				find_maxbong();
				arr[i][j] += a;
			}
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t) {
		memset(arr, 0, sizeof(arr));
		max_height_result = 0;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		dig();
		cout << "#" << t << " " << max_height_result << "\n";
	}
	system("pause");
	return 0;
}