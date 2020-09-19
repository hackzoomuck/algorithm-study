#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;//체스판 크기, 말의 개수
struct horse{//말의 좌표값과 방향
	int x;
	int y;
	int d;
} h[11];
//1:→ 2:← 3:↑ 4:↓
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int change[5] = { 0,2,1,4,3 };//반대로 방향전환
int chess[13][13];//체스판 색
vector<int> chess_horse[13][13];//체스판 위 말

int move_hor(int m) { //말 이동 함수
	int hx = h[m].x + dx[h[m].d];
	int hy = h[m].y + dy[h[m].d];
	if (hx <= 0 || hx > n || hy <= 0 || hy > n || chess[hx][hy] == 2) {
		h[m].d = change[h[m].d];
		hx = h[m].x + dx[h[m].d];
		hy = h[m].y + dy[h[m].d];
		if (hx <= 0 || hx > n || hy <= 0 || hy > n || chess[hx][hy] == 2) {
			return chess_horse[h[m].x][h[m].y].size();
		}
	}

	vector<int> &now = chess_horse[h[m].x][h[m].y];
	vector<int> &after = chess_horse[hx][hy];
	auto hor_st = find(now.begin(), now.end(), m);

	if (chess[hx][hy] == 1) {
		reverse(hor_st, now.end());
	}
	for (auto it = hor_st; it != now.end(); it++) {
		h[*it].x = hx;
		h[*it].y = hy;
		after.push_back(*it);
	}
	now.erase(hor_st, now.end());
	return after.size();
}

int simul() {//게임을 진행
	int chess_turn = 0;
	int hor_cnt = 0;
	for (chess_turn = 1; chess_turn <= 1000; chess_turn++) {
		for (int j = 0; j < k; j++) {
			hor_cnt= move_hor(j);
			if (hor_cnt >= 4) return chess_turn;
		}
	}
	return -1;
}
int main() {
	cin >> n >> k;
	// 주의!! 문제 조건을 잘보자! 인덱스가 0에서 시작이 아니다!
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> chess[i][j];
		}
	}
	for (int a = 0; a < k; a++) {
		horse& hor = h[a];
		cin >> hor.x >> hor.y >> hor.d;
		chess_horse[hor.x][hor.y].push_back(a);
	}
	cout << simul();
	system("pause");
	return 0;
}