#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

int map[21][21] = { 0, };
int n;
int sh_x = 0, sh_y = 0, sh_time = 0, sh_size = 2, sh_eat_cnt = 0;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

struct {
	vector<pair<int, int>> v;
	int fish_size;
}fish[7];

void fishing() {
	vector<pair<pair<int, int>,int>> top_left_fish;
	int min_v = 987654321;
	map[sh_x][sh_y] = 0;
	while (1) {
		if (!top_left_fish.empty()) {
			sort(top_left_fish.begin(), top_left_fish.end());
			sh_eat_cnt++;
			sh_time += min_v;
			int fi_s = top_left_fish[0].second;
			int fx = top_left_fish[0].first.first;
			int fy = top_left_fish[0].first.second;
			for (int j = 0; j < fish[fi_s].fish_size; j++) {
				if (fish[fi_s].v[j].first == fx && fish[fi_s].v[j].second == fy) { //해당 x,y 위치의 fish를 없애준다.
					map[fx][fy] = 0;
					sh_x = fx;
					sh_y = fy;
					fish[fi_s].v.erase(fish[fi_s].v.begin() + j);
					fish[fi_s].fish_size--;
					break;
				}
			}
			top_left_fish.clear();
			min_v = 987654321;
		}
		int visit[21][21] = { 0, };
		int can_eat_fish = 0;
		if (sh_eat_cnt == sh_size) { //먹은 수가 물고기 크기일 때, 
			sh_eat_cnt = 0; 
			sh_size++;
		}
		for (int i = 1; i < sh_size; i++) {
			can_eat_fish += fish[i].fish_size;
		}
		if (!can_eat_fish) return; //먹을 수 있는 물고기 없음, 엄마 상어 콜

		if (can_eat_fish == 1) { //물고기 1마리일 경우.
			for (int i = 1; i <= 6; i++) {
				if (fish[i].fish_size) {
					sh_time += abs(sh_x - fish[i].v[0].first) + abs(sh_y - fish[i].v[0].second);
					sh_x = fish[i].v[0].first; sh_y = fish[i].v[0].second;
					map[sh_x][sh_y] = 0;
					fish[i].v.clear();
					fish[i].fish_size--;
					sh_eat_cnt++;
					if (sh_eat_cnt == sh_size) { //먹은 수가 물고기 크기일 때, 
						sh_eat_cnt = 0;
						sh_size++;
						break;
					}
					else return;
				}
			}
			continue;
		}

		queue<pair<int, int>> q;
		q.push({ sh_x,sh_y });
		map[sh_x][sh_y] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < n && !visit[nx][ny] && map[nx][ny] <= sh_size) {
					visit[nx][ny] = visit[x][y] + 1;
					if (visit[nx][ny] > min_v) break;
					q.push({ nx,ny });
					if (map[nx][ny] < sh_size && map[nx][ny] > 0) {
						if (min_v >= visit[nx][ny]) {
							min_v = visit[nx][ny];
							
							top_left_fish.push_back({{nx,ny},map[nx][ny]});
						}
					}
				}
			}//for 4방향 끝
		}// bfs while 끝

	}
}

int main() {
	//std::ifstream fin("C:\\a.txt");
	//fin>>n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//fin>>map[i][j];
			cin >> map[i][j];

			if (map[i][j] == 9) {
				sh_x = i; sh_y = j;
				continue;
			}
			fish[map[i][j]].v.push_back({ i,j });
		}
	}
	for (int i = 1; i <= 6; i++) {
		fish[i].fish_size = fish[i].v.size();
	}
	fishing();
	cout << sh_time;

	system("pause");
	return 0;
}
