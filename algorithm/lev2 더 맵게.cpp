#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    while (!scoville.empty()) {
        sort(scoville.begin(), scoville.end());
        if (scoville[0] < K) {
            if (scoville.size() >= 2) {
                int newscoville = scoville[0] + (scoville[1] * 2);
                scoville.erase(scoville.begin(), scoville.begin() + 2);
                scoville.push_back(newscoville);
                ++answer;
            }
            else {
                return answer = -1;
            }
        }
        else  return answer;
    }
}
