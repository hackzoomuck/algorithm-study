#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int idx, int sum, int target, vector<int> num) {
    if (idx == num.size()) {
        if (sum == target) {
            ++answer;
        }
        return;
    }
    dfs(idx + 1, sum + num[idx], target, num);
    dfs(idx + 1, sum - num[idx], target, num);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);
    return answer;
}

