#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[101] = { 0, };

int find(int x) {
    if (arr[x] == x) {
        return x;
    }
    else {
        return find(arr[x]);
    }
}

bool union_(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    else {
        arr[y] = x;
        return true;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> incosts;
    incosts.resize(costs.size());
    for (int a = 0; a < n; a++) {
        arr[a] = a;
    }
    for (int i = 0; i < costs.size(); i++) {
        for (int k = 0; k < 3; k++) {
            incosts[i].push_back(costs[i][(k + 2) % 3]);
        }
    }
    sort(incosts.begin(), incosts.end());

    for (int j = 0; j < incosts.size(); j++) {
        if (union_(incosts[j][1], incosts[j][2])) {
            answer += incosts[j][0];
        }
    }
    return answer;
}


int main() {
    int n = 4;
    vector<vector<int>> v = { {0,1,1} ,{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    solution(n, v);
    system("pause");
    return 0;
}