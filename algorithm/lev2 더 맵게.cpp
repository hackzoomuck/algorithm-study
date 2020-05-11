#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while (!pq.empty()) {
        if (pq.top() < K) {
            if (pq.size() >= 2) {
                int pTop = pq.top();
                pq.pop();
                int newscoville = pTop + (pq.top() * 2);
                pq.pop();
                pq.push(newscoville);
                ++answer;
            }
            else {
                return answer = -1;
            }
        }
        else  return answer;
    }
}
