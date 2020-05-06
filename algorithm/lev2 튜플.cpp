//hash table�� Ǯ�� �ʹ�. map�� value�� sort�ұ�?
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer; 
    unordered_map<string, int> um; // ���ڿ��� �ش� ���ڸ� key, ������ value�� �ϴ� hash table
    vector<pair<int, string>>keys; // um�� value�� sort�ϱ� ���ؼ� ����ϴ� ����
    string tmp = ""; 

    // ���ڿ��� unorederd_map�� key�� value�� �����ϴ� for��.
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

    // um�� key�� value�� vector ������ ����
    for (auto& it : um) {
        keys.push_back(make_pair(it.second, it.first));
    }
    // value�� ������������ ����
    sort(keys.rbegin(), keys.rend());
    // value ������������ key�� answer�� ����.
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
