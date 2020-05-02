#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();//n*n�� n
    vector<vector<int>> tmp;//�����̱� ���
    tmp.resize(n);//n����ŭ resize���ش�.
    stack<int> s;

    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            //0���� ������� ������ �����̱� ��迡 �ִ´�.
            if (board[i][j]) {
                tmp[j].push_back(board[i][j]);
            }
            else {
                break;
            }
        }
    }

    //moves�����ϸ鼭 s�� ���� �ױ�.
    for (int k = 0; k < moves.size(); k++) {
        int pos = moves[k] - 1;
        if (!tmp[pos].empty()) {

            if (!s.empty() && tmp[pos].back() == s.top()) {
                s.pop();
                answer += 2;
            }
            else {
                s.push(tmp[pos].back());
            }
            tmp[pos].pop_back();
        }
    }

    return answer;
}

void main() {
    vector<vector<int>> a = { {0,0,0,0,0} ,{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> b = { 1,5,3,5,1,2,1,4 };
    solution(a, b);
}