#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> v;
    vector<int> result;
    //iũ��� ����� ���ڿ��� �����ϱ� ����.
    v.resize(s.size(), "");

    //iũ��� ����, s.size()�� �ƴ� s.size()/2��ŭ���� �����ص� �ȴٰ� �ϴµ� ��������.
    for (int i = 1; i <= s.size(); i++) {
        string tmp = s;
        //tmp�� 0�� �ɶ����� for�� ������.
        for (int j = 0; j < tmp.size();) {
            //iũ���� ���ڿ� �񱳸� ���� bool ����.
            bool check = true;
            //iũ�⸸ŭ �ݺ��� ���ڿ��� ������ ���ϴ� int ����.
            int cnt = 1;

            //���ڿ��� ���� �ʰų� tmp�� ������� ��� while�� Ż��
            while (check && !tmp.empty()) {
                //iũ�⸸ŭ �ٷ� ���� ���ڿ��� ��
                for (int k = 0; k < i; k++) {
                    //k+i�� tmp �ε����� ����ų� ���ڰ� ���� ���� ��쿡
                    //check = false�ϰ� forŻ��.
                    if (k + i > tmp.size() - 1 || tmp[k] != tmp[k + i]) {
                        check = false;
                        break;
                    }
                }
                //���ڿ��� �ݺ��Ǹ�, ���� ������Ű��, tmp���� �ش� ���ڿ��� ����.
                if (check) {
                    cnt++;
                    tmp.erase(0, i);
                }
            }
            //�ݺ��� ���ڿ��̸� ���ڸ� �ٿ��ֱ� ����.
            if (cnt != 1) v[i - 1].append(to_string(cnt));
            //iũ�⺸�� ���ڿ��� �� ���ų� ���� ��쿡 v[i-1]�� ���ڿ� ����.
            if (tmp.size() >= i) {
                v[i - 1].append(tmp, 0, i);
                tmp.erase(0, i);
            }
            //iũ�⺸�� ���ڿ��� ���� ��� ���� ���ڿ��� v[i-1]�� ����.
            else {
                v[i - 1].append(tmp);
                tmp.clear();
            }
        }
        //result���� ����� ���ڿ��� ���̸� ������.
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
