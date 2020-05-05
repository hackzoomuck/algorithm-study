#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    string change_razer; //레이저 부분을 *로 변경해서 저장할 변수
    //레이저 부분 검사해서 change_razer변수에 저장.
    for (int i = 0; i < arrangement.size()-1; i++) {
        if (arrangement[i] == '(' && arrangement[i + 1] == ')') {
            change_razer.append(1,'*');
            i++;
        }
        else {
            change_razer.append(1,arrangement[i]);
        }
    }
    //저장안된 마지막 문자열을 저장하기 위한 조건문.
    if (!(arrangement[arrangement.size() - 2] == '(' && arrangement[arrangement.size() - 1] == ')')) {
        change_razer.append(1, arrangement[arrangement.size() - 1]);
    }

    vector<pair<char, int>> v; //stack과 같이 사용, int에는 지나온 레이저 수를 저장함.
    for(int j = 0; j < change_razer.size(); j++) {
        if (change_razer[j] == '(') v.push_back(make_pair('(',0));
        else if (change_razer[j] == '*'){
            for (int k = 0; k < v.size(); k++) {
                v[k].second++;
            }
        }
        else {
            answer += v.back().second + 1;
            v.pop_back();
        }
    }

    return answer;
}

int main() {
    string s = "()(((()())(())()))(())";
    solution(s);
    system("pause");
}

//다른 사람 코드
//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int solution(string a) {
//    int answer = 0;
//    stack<char> s;
//
//    for (int i = 0; i < a.length(); i++) {
//        if (a[i] == '(')
//            s.push(a[i]);
//        else {
//            s.pop();
//            if (a[i - 1] == '(')
//                answer += s.size();
//            else
//                answer++;
//        }
//    }
//    return answer;
//}