#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int v, e, s, x, y, z, d[20002];
vector<vector<pair<int, int>>> vt;
int main() {
	scanf("%d%d%d", &v, &e, &s);
	vt.resize(v + 1);
	for (int i = 0; i < e; i++) {
		scanf("%d%d%d", &x, &y, &z);
		vt[x].push_back({ y,z });
	}
	memset(d, -1, sizeof(d));
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	while (pq.size()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (d[here] != -1)
			continue;
		d[here] = cost;
		for (auto it : vt[here]) {
			int next = it.first;
			int acost = -it.second - cost;
			if (d[next] != -1)
				continue;
			pq.push({ acost,next });
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == -1)puts("INF");
		else printf("%d\n", d[i]);
	}

	return 0;
}
