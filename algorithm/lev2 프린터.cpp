//queue이용해서 실제로 움직이는 것처럼 풀 예정
//똑같은 queue만들어서 검사할 위치의 숫자만 1, 그 외는 0를 저장해서 
//1이 push 될때를 찾는다.
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> tmp_pri;
    queue<bool> check;
    vector<int> v_pri = priorities;//내림차순 정렬을 할 vector

    //queue 자료구조에 대기목록 저장, 검사할 위치의 인쇄물은 true, 그외의 위치에는 false를 넣기
    for (int i = 0; i < priorities.size(); i++) {
        tmp_pri.push(priorities[i]);
        if (i == location)check.push(true);
        else check.push(false);
    }

    //내림차순 정렬
    sort(v_pri.rbegin(), v_pri.rend());

    while (!check.empty()) {
        //맨 앞이 중요가 가장 높을 경우
        if (tmp_pri.front() == v_pri[0]) {
            //location의 인쇄물 일 때,
            if (check.front()) {
                return ++answer;
            }
            //location의 인쇄물 아닐 때,
            else {
                answer++;
                tmp_pri.pop();
                check.pop();
                v_pri.erase(v_pri.begin());
            }
        }
        //뒤에 더 큰 중요 인쇄물이 있을 경우
        else {
            tmp_pri.push(tmp_pri.front());
            tmp_pri.pop();
            check.push(check.front());
            check.pop();
        }
    }

    return answer;
}

void main() {

    vector<int>v_input = { 2,1,3,2 };
    solution(v_input, 2);
}