#include <iostream>
#include <queue>
#include <math.h>
#include <cstring>
#define INF 123456789
using namespace std;

int arr[1002][1002];
int rearr[1002][1002];
int djistar[1002];
int redjistar[1002];


struct node {
	int time, vertex;
};

bool operator<(node a, node b) { 
	return a.vertex > b.vertex;
}

priority_queue<node> pq;
node nd;

int main() {
	int n, m, x;
	int a, b, t;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) {
		memset(arr[i], -1, sizeof(arr[i]));
		memset(rearr[i], -1, sizeof(rearr[i]));
	}
	memset(djistar, INF, sizeof(djistar));
	memset(redjistar, INF, sizeof(redjistar));
	for (int j = 0; j < m; j++) {
		cin >> a >> b >> t;
		arr[a][b] = t;
		rearr[b][a] = t;
	}

	pq.push(node{ 0, x });
	djistar[x] = 0;
	// x -> all vertex 
	while (!pq.empty()) {
		nd = pq.top();
		pq.pop();
		for (int k = 1; k <= n; k++) {
			if (arr[nd.vertex][k] != -1) {
				if (nd.time + arr[nd.vertex][k] < djistar[k]) {
					djistar[k] = nd.time + arr[nd.vertex][k];
					pq.push(node{ djistar[k],k });
				}
			}
		}
	}

	pq.push(node{ 0, x });
	redjistar[x] = 0;
	//역 x -> all vertex : 어짜피 집에서 x로 가는 시간을 알고 싶은 거니, 간선의 방향을 바꿔서 x에서 출발시키자.
	while (!pq.empty()) {
		nd = pq.top();
		pq.pop();
		for (int k = 1; k <= n; k++) {
			if (rearr[nd.vertex][k] != -1) {
				if (nd.time + rearr[nd.vertex][k] < redjistar[k]) {
					redjistar[k] = nd.time + rearr[nd.vertex][k];
					pq.push(node{ redjistar[k],k });
				}
			}
		}
	}


	int answer = 0;
	for (int l = 1; l <= n; l++) {
		answer = max(redjistar[l] + djistar[l], answer);
	}
	cout << answer<<"\n";
	system("pause");
	return 0;
}
