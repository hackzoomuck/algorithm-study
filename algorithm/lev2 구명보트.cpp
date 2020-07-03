#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool greater_peo(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0, right = people.size()-1;
    sort(people.begin(), people.end(), greater_peo);
    while (left <= right ) {
        if (people[left] + people[right] <= limit) {
            --right;
        }
        ++left;
        ++answer;
    }
    return answer;
}
 