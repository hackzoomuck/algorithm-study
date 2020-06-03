//숫자는 맞지만, 위치 틀림 = 볼
//숫자와 위치 모두 맞음, 스트라이크
//숫자와 위치가 모두 틀렸을 때 = 아웃
#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<int>> bas, int bt) {
	for (int c1 = 0; c1 < bas.size(); c1++) {
		//스트라이크랑 볼을 어떻게 잘 비교할 수 있을까나?
		//스트라이크있는부분 삭제하고 볼 비교
		string a = to_string(bas[c1][0]);
		string b = to_string(bt);
		for (int c2 = 0; c2 < a.size(); c2++) {
			if (a[c2] == b[c2]) {
				a.erase(c2,1);
				b.erase(c2,1);
				bas[c1][1]--;
				c2--;
			}
		}
		if (bas[c1][1] == 0) {
			for (int c3 = 0; c3 < a.size(); c3++) {
				for (int c4 = 0; c4 < a.size(); c4++) {
					if (a[c3] == b[c4]) bas[c1][2]--;
				}
			}
			if (bas[c1][2] != 0)return false;
		}
		else return false;

	}
	return true;

	//다른 코드 한개를 기준으로 같은 위치로 strike 찾고, 다른 위치(mod로)과 같은지 비교해서 ball 찾음.
	//string a, b를 사용한다고 생각하고 코드 짜기.
	//각 자리의 숫자가 다 다름.
	/*for (int i = 0; i < 3; i++) {
		if (a[i] == b[i]) strike++;
		if (a[i] == b[(i + 1) % 3] || a[i] == b[(i + 2) % 3]) ball++;
	}*/
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	int tmp = 0;
	//완전탐색으로 123~987 모두 비교 
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (i == j)continue;
			for (int k = 1; k < 10; k++) {
				if (i == k || j == k) continue;
				tmp = i * 100 + j * 10 + k;
				if (check(baseball, tmp)) answer++;
			}
		}
	}
	//다른 코드
	/*for (int i = 123; i <= 987; i++) {
		10, 1자리에 0 나오는 것, 각 자리가 같은 경우를 배제하기.
	}*/
	return answer;
}

int main() {
	vector<vector<int>> v = { {123, 1, 1} ,{356, 1, 0},{327, 2, 0},{489, 0, 1} };
	solution(v);
	return 0;
}