#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> v;
	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i] - 1] != 0) {
				if (v.size()) {
					if (v.back() == board[j][moves[i] - 1]) {
						answer += 2;
						v.pop_back();
					}
					else {
						v.push_back(board[j][moves[i] - 1]);
					}
				}
				else {
					v.push_back(board[j][moves[i] - 1]);
				}
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}
	cout << answer << "\n";
	return answer;
}

int main() {
	vector<vector<int>> b;
	b.resize(5);
	b[0] = { 0,0,0,0,0 };
	b[1] = { 0,0,1,0,3 };
	b[2] = { 0,2,5,0,1 };
	b[3] = { 4,2,4,4,2 };
	b[4] = { 3,5,1,3,1 };
	vector<int> c;
	c = { 1,5,3,5,1,2,1,4 };
	solution(b, c);
	system("pause");
	return 0;
}
