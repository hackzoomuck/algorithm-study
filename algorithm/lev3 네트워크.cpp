#include <string>
#include <vector>

using namespace std;

bool visit[201] = { false, };
int answer = 0;

void dfs(int idx, vector<vector<int>> c) {
	visit[idx] = true;
	for (int j = 0; j < c.size(); j++) {
		if (idx == j) continue;
		if (!visit[j] && c[idx][j]) {
			dfs(j, c);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			dfs(i, computers);
			answer++;
		}
	}
	return answer;
}
