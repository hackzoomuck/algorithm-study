#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[17][17] = { 0, };
int cache[16][1 << 16]; //메모이제이션을 위한 배열 cache[현재 방문중인 도시][비트마스크값으로 visited의미]
const int INF = 987654321;

int tsp(int here, int visited) {
	if (visited == (1 << n) - 1) {
		if (arr[here][0] != 0) {
			return arr[here][0];
		}
		else return INF;
	}
	int& result = cache[here][visited];
	if (result != -1)
		return result;
	result = INF;
	for (int next = 0; next < n; next++) {
		//방문한적이 없고 가는 길이 있으면 수행.
		if (!(visited & (1 << next)) && arr[here][next]) {
			int candidate = arr[here][next] + tsp(next, visited + (1 << next));
			result = min(result, candidate);
		}
	}
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << tsp(0, 1) << endl;
	return 0;
}