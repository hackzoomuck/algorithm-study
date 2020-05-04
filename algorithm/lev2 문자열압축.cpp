#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> v;
    vector<int> result;
    //i크기로 압축된 문자열을 저장하기 위함.
    v.resize(s.size(), "");

    //i크기로 압축, s.size()가 아닌 s.size()/2만큼까지 실행해도 된다고 하는데 오류난다.
    for (int i = 1; i <= s.size(); i++) {
        string tmp = s;
        //tmp가 0이 될때까지 for문 실행함.
        for (int j = 0; j < tmp.size();) {
            //i크기의 문자열 비교를 위한 bool 변수.
            bool check = true;
            //i크기만큼 반복된 문자열의 개수를 구하는 int 변수.
            int cnt = 1;

            //문자열이 같지 않거나 tmp가 비어있을 경우 while문 탈출
            while (check && !tmp.empty()) {
                //i크기만큼 바로 다음 문자열과 비교
                for (int k = 0; k < i; k++) {
                    //k+i가 tmp 인덱스를 벗어나거나 문자가 같지 않은 경우에
                    //check = false하고 for탈출.
                    if (k + i > tmp.size() - 1 || tmp[k] != tmp[k + i]) {
                        check = false;
                        break;
                    }
                }
                //문자열이 반복되면, 개수 증가시키고, tmp에서 해당 문자열을 지움.
                if (check) {
                    cnt++;
                    tmp.erase(0, i);
                }
            }
            //반복된 문자열이면 숫자를 붙여주기 위함.
            if (cnt != 1) v[i - 1].append(to_string(cnt));
            //i크기보다 문자열이 더 많거나 같을 경우에 v[i-1]에 문자열 붙임.
            if (tmp.size() >= i) {
                v[i - 1].append(tmp, 0, i);
                tmp.erase(0, i);
            }
            //i크기보다 문자열이 작을 경우 남은 문자열을 v[i-1]에 붙임.
            else {
                v[i - 1].append(tmp);
                tmp.clear();
            }
        }
        //result에는 압축된 문자열의 길이를 저장함.
        result.push_back(v[i - 1].size());
    }
    sort(result.begin(), result.end());
    answer = result[0];
    return answer;
}

void main() {
    string input = "aab";
    solution(input);

}
