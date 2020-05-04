//queue�̿��ؼ� ������ �����̴� ��ó�� Ǯ ����
//�Ȱ��� queue���� �˻��� ��ġ�� ���ڸ� 1, �� �ܴ� 0�� �����ؼ� 
//1�� push �ɶ��� ã�´�.
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> tmp_pri;
    queue<bool> check;
    vector<int> v_pri = priorities;//�������� ������ �� vector

    //queue �ڷᱸ���� ����� ����, �˻��� ��ġ�� �μ⹰�� true, �׿��� ��ġ���� false�� �ֱ�
    for (int i = 0; i < priorities.size(); i++) {
        tmp_pri.push(priorities[i]);
        if (i == location)check.push(true);
        else check.push(false);
    }

    //�������� ����
    sort(v_pri.rbegin(), v_pri.rend());

    while (!check.empty()) {
        //�� ���� �߿䰡 ���� ���� ���
        if (tmp_pri.front() == v_pri[0]) {
            //location�� �μ⹰ �� ��,
            if (check.front()) {
                return ++answer;
            }
            //location�� �μ⹰ �ƴ� ��,
            else {
                answer++;
                tmp_pri.pop();
                check.pop();
                v_pri.erase(v_pri.begin());
            }
        }
        //�ڿ� �� ū �߿� �μ⹰�� ���� ���
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