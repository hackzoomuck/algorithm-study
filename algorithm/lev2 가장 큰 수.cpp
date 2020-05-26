#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//���� ū ���� ����� ���� ���Լ�.
bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vs;

    //������ ���ڿ��� �ٲ��ִ� �ݺ���.
    for (int i = 0; i < numbers.size(); i++) {
        vs.push_back(to_string(numbers[i]));
    }
    sort(vs.begin(), vs.end(), cmp);
    
    //0, 0, 0 �� ���� �迭�� �־����� �� 000�� �ƴ� 0 ����� ���� ���ǹ�.
    if (vs[0] == "0") return answer += vs[0];
    for (int j = 0; j < vs.size(); j++) {
        answer += vs[j];
    }
    return answer;
}
