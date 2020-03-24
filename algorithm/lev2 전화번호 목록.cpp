#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//배열 중 가장 짧은 길이를 가진 것의 길이만큼만 value로 넣는다
bool solution(vector<string> phone_book) {
	bool answer = true;
	int len = 20;
	for (int j = 0; j < phone_book.size(); j++) {
		if (len > phone_book[j].size()) len = phone_book[j].size();
	}
	unordered_map<string, int> um;

	for (int i = 0; i < phone_book.size(); i++) {
		string tmp = "";
		tmp.append(phone_book[i], 0, len);
		um[tmp]++;
		if (um[tmp] > 1) return false;
	}

	return answer;
}

void main() {

	vector<string> v;
	v.push_back("0123246");
	v.push_back("1195524421");
	v.push_back("23456");
	v.push_back("119");
	solution(v);
}
