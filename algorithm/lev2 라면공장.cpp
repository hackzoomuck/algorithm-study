#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>, less<int>> pq; // max heap
	int index = 0; //dates, supplies의 index입니다.

	for (int i = 0; i < k; i++) {// k일 전까지 stock가 1씩 줄어들며,
		//해당 날짜에 supplies를 pq에 push 합니다.
		if (dates[index] == i) {
			pq.push(supplies[index]);
			++index;
		}
		//stock가 0일 때, 가장 큰 supplie를 stock에 저장하고 pq에서 pop 합니다.
		if (stock == 0) {
			stock = pq.top();
			pq.pop();
			++answer;
		}
		--stock;
	}
	return answer;
}
