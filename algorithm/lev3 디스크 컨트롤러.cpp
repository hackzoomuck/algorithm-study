#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
	sort(jobs.begin(), jobs.end());//��û�ð� ������������ ���� nlogn : 10^6*8 (n=10^5) 0.08sec
	int answer = 0;
	int use = 0;//������� �۾��� ������ �˷��ִ� ����.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //<�۾���, �����ð�>�� minheap���� ������ �켱���� ť pq.
	int index = 0;//job�� �ε����� ���� ����.
	int v_cnt = jobs.size();//jobs�� �� ���Ǹ� Ż���ϱ� ���� �������� ���� ����.
	int curtime = 0;//���� �ð�.

	while (v_cnt) { //���jobs �� ������. 

		if (index < jobs.size() && jobs[index][0] <= curtime) { //�ش�ð� �ȿ� ��û�� ������ ���.
			pq.push(pair<int, int>(jobs[index][1], jobs[index][0])); //���� O(log n)
			++index;
			continue;
		}

		if (pq.empty()) { //��û�� �۾��� ���� ���, �ð��� 1������Ű�� continue.
			++curtime;
			continue;
		}
		else { //��û�� �۾��� ���� ���.
			pair<int, int> pu;
			pu = pq.top();
			pq.pop();
			answer += curtime - pu.second + pu.first;
			curtime += pu.first;
			--v_cnt;
		}

	}
	return answer / jobs.size();
}
