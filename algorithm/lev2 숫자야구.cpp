//���ڴ� ������, ��ġ Ʋ�� = ��
//���ڿ� ��ġ ��� ����, ��Ʈ����ũ
//���ڿ� ��ġ�� ��� Ʋ���� �� = �ƿ�
#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<int>> bas, int bt) {
	for (int c1 = 0; c1 < bas.size(); c1++) {
		//��Ʈ����ũ�� ���� ��� �� ���� �� �����?
		//��Ʈ����ũ�ִºκ� �����ϰ� �� ��
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

	//�ٸ� �ڵ� �Ѱ��� �������� ���� ��ġ�� strike ã��, �ٸ� ��ġ(mod��)�� ������ ���ؼ� ball ã��.
	//string a, b�� ����Ѵٰ� �����ϰ� �ڵ� ¥��.
	//�� �ڸ��� ���ڰ� �� �ٸ�.
	/*for (int i = 0; i < 3; i++) {
		if (a[i] == b[i]) strike++;
		if (a[i] == b[(i + 1) % 3] || a[i] == b[(i + 2) % 3]) ball++;
	}*/
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	int tmp = 0;
	//����Ž������ 123~987 ��� �� 
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
	//�ٸ� �ڵ�
	/*for (int i = 123; i <= 987; i++) {
		10, 1�ڸ��� 0 ������ ��, �� �ڸ��� ���� ��츦 �����ϱ�.
	}*/
	return answer;
}

int main() {
	vector<vector<int>> v = { {123, 1, 1} ,{356, 1, 0},{327, 2, 0},{489, 0, 1} };
	solution(v);
	return 0;
}