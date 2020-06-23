#include <string>
#include <vector>
using namespace std;

//�� �ڽ��� ���� -1, +1

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer;
    vector<int> tmp_lost = lost;
    vector<int> tmp_res = reserve;

    //�ڱ� �ڽſ��� ������
    for (int i = 0; i < tmp_res.size(); i++) {
        for (int j = 0; j < tmp_lost.size(); j++) {
            if (tmp_res[i] == tmp_lost[j]) {
                tmp_res.erase(tmp_res.begin() + i);
                tmp_lost.erase(tmp_lost.begin() + j);
                --i;
                --j;
            }
            if (i < 0)break; // i�� -1�� �Ǵ� ��� ó��.
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