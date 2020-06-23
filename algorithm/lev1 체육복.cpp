#include <string>
#include <vector>
using namespace std;

//나 자신을 보고 -1, +1

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer;
    vector<int> tmp_lost = lost;
    vector<int> tmp_res = reserve;

    //자기 자신에게 빌려줌
    for (int i = 0; i < tmp_res.size(); i++) {
        for (int j = 0; j < tmp_lost.size(); j++) {
            if (tmp_res[i] == tmp_lost[j]) {
                tmp_res.erase(tmp_res.begin() + i);
                tmp_lost.erase(tmp_lost.begin() + j);
                --i;
                --j;
            }
            if (i < 0)break; // i가 -1이 되는 경우 처리.
        }
    }

    for (int i = 0; i < tmp_res.size(); i++) {
        for (int j = 0; j < tmp_lost.size(); j++) {
            if (tmp_res[i]-1 == tmp_lost[j] || tmp_res[i] + 1 == tmp_lost[j]) {
                tmp_res.erase(tmp_res.begin() + i);
                tmp_lost.erase(tmp_lost.begin() + j);
                --i;
                --j;
            }

            if (i < 0)break;
        }
    }
    answer = n - tmp_lost.size();
    return answer;
}

int main() {
    vector<int> l = { 5,6 };
    vector<int> r = { 4,5 };

    //for (int i : l) cout << i; => 5 6

    solution(6, l, r);
    system("pause");
}