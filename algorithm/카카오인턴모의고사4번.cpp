#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	vector<pair<bool, long long>> room;
	room.resize(k + 1);
	for (long long i = 0; i < room_number.size(); i++) {
		long long rn = room_number[i];
		if (room[rn].first != true) {
			answer.push_back(rn);
			room[rn].first = true;
			while (++rn) {
				if (room[rn].first != true) {
					room[room_number[i]].second = rn;
					break;
				}
			}
		}
		else {
			long long rn2 = rn;
			vector <int> vrn;
			while (room[rn2].first == true) {
				vrn.push_back(rn2);
				if (room[rn2].second == 0) {
					rn2++;
					continue;
				}
				rn2 = room[rn2].second;
			}
			answer.push_back(rn2);
			room[rn2].first = true;
			while (++rn2) {
				if (room[rn2].first != true) {
					for (long long j = 0; j < vrn.size(); j++) {
						room[vrn[j]].second = rn2;
					}
					break;
				}
			}
			vrn.clear();
		}
	}
	return answer;
}

int main() {

	vector<long long> input;
	input = { 1,3,4,1,3,1 };
	solution(10, input);
	system("pause");
	return 0;
}
