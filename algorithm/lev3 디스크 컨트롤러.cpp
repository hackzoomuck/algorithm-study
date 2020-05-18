#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
	sort(jobs.begin(), jobs.end());//요청시간 오름차순으로 정렬 nlogn : 10^6*8 (n=10^5) 0.08sec
	int answer = 0;
	int use = 0;//사용중인 작업이 있음을 알려주는 변수.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //<작업량, 도착시간>을 minheap으로 저장할 우선순위 큐 pq.
	int index = 0;//job의 인덱스로 사용될 변수.
	int v_cnt = jobs.size();//jobs가 다 사용되면 탈출하기 위한 조건으로 사용된 변수.
	int curtime = 0;//현재 시간.

	while (v_cnt) { //모든jobs 다 수행함. 

		if (index < jobs.size() && jobs[index][0] <= curtime) { //해당시간 안에 요청이 들어왔을 경우.
			pq.push(pair<int, int>(jobs[index][1], jobs[index][0])); //삽입 O(log n)
			++index;
			continue;
		}

		if (pq.empty()) { //요청된 작업이 없을 경우, 시간은 1증가시키고 continue.
			++curtime;
			continue;
		}
		else { //요청된 작업이 있을 경우.
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
