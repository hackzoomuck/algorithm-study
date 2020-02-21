#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
int visit[301][301] = { 0, };

int main() {
	int test, chess, start_x, start_y, end_x, end_y;
	cin >> test;
	while (test--) {
		queue<pair<int, int>> q;
		cin >> chess;
		for (int i = 0; i < chess; i++) {
			for (int j = 0; j < chess; j++) {
				visit[i][j] = 0;
			}
		}

		int count = 0;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		q.push(make_pair(start_x, start_y));
		visit[start_x][start_y] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == end_x && y == end_y) break;
	
			for (int d = 0; d < 8; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx == start_x && ny == start_y) continue;
				if (nx >= 0 && nx < chess && ny >= 0 && ny < chess && visit[nx][ny] == 0) {
					visit[nx][ny] = visit[x][y]+1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		cout << visit[end_x][end_y] << "\n";
	}
	system("pause");
	return 0;
}