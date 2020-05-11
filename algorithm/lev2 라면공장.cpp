#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>, less<int>> pq; // max heap
	int index = 0; //dates, supplies�� index�Դϴ�.

	for (int i = 0; i < k; i++) {// k�� ������ stock�� 1�� �پ���,
		//�ش� ��¥�� supplies�� pq�� push �մϴ�.
		if (dates[index] == i) {
			pq.push(supplies[index]);
			++index;
		}
		//stock�� 0�� ��, ���� ū supplie�� stock�� �����ϰ� pq���� pop �մϴ�.
		if (stock == 0) {
			stock = pq.top();
			pq.pop();
			++answer;
		}
		--stock;
	}
	return answer;
}
