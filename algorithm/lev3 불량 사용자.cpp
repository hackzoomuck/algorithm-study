//dfs로 완탐하고, set이용해서 중복을 없애준다.
#include <string>
#include <vector>
#include <set>

using namespace std;

set <int> s;
bool check[8];
int len = 0;

void dfs(vector<string>& us, vector<string>& ba, int i, int n) { // i는 ban_id크기만큼 증가가능한 index의 크기, n은 중복을 검사하기 위한 2진수 저장 변수
    if (i == len) {
        s.emplace(n);
        return;
    }

    for (int a = 0; a < us.size(); a++) {
        if (us[a].size() != ba[i].size())
            continue;

        if (check[a])
            continue;

        int b = 0;
        for (b ; b < us[a].size(); b++) {
            if (ba[i][b] == '*')
                continue;
            if (ba[i][b] != us[a][b])
                break;
        }
        if (b == us[a].size()) {
            check[a] = true;
            dfs(us, ba, i + 1, n | (1 << a));
            check[a] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    len = banned_id.size();
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}

void main() {
    vector<string> iu = { "fdo", "fdi", "cdo", "ab", "fr" };
    vector<string> ib = { "fd*", "*do", "**", "**" };
    solution(iu, ib);
    system("pause");
}