#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//가장 큰 수를 만들기 위한 비교함수.
bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vs;

    //정수를 문자열로 바꿔주는 반복문.
    for (int i = 0; i < numbers.size(); i++) {
        vs.push_back(to_string(numbers[i]));
    }
    sort(vs.begin(), vs.end(), cmp);
    
    //0, 0, 0 과 같은 배열이 주어졌을 때 000이 아닌 0 출력을 위한 조건문.
    if (vs[0] == "0") return answer += vs[0];
    for (int j = 0; j < vs.size(); j++) {
        answer += vs[j];
    }
    return answer;
}
