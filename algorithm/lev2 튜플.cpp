//hash table로 풀고 싶다. map의 value로 sort할까?
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer; 
    unordered_map<string, int> um; // 문자열에 해당 문자를 key, 개수를 value로 하는 hash table
    vector<pair<int, string>>keys; // um의 value로 sort하기 위해서 사용하는 변수
    string tmp = ""; 

    // 문자열을 unorederd_map에 key와 value로 저장하는 for문.
    for (int j = 1; j < s.size()-1; j++) {
        if (s[j] == '{' || s[j] == ' ') continue;
        if (s[j] == ',' || s[j] == '}') {
            if (tmp != "") {
                um[tmp]++;
                tmp = "";
            }
        }
        else {
            tmp.append(1, s[j]);
        }
    }

    // um의 key와 value를 vector 변수에 복사
    for (auto& it : um) {
        keys.push_back(make_pair(it.second, it.first));
    }
    // value로 내림차순으로 정렬
    sort(keys.rbegin(), keys.rend());
    // value 내림차순으로 key를 answer에 저장.
    for (int i = 0; i < keys.size(); i++) {
        answer.push_back(stoi(keys[i].second));
    }
    return answer;
}

void main() {

    string ss = "{ {2}, { 2,1 }, { 2,1,3 }, { 2,1,3,4 }}";
    solution(ss);
    system("pause");

}
