#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	int len = phone_book[0].size();
	unordered_map<string, int> um;

	for (int i = 0; i < phone_book.size(); i++) {
		string tmp = "";
		tmp.append(phone_book[i], 0, len);
		if (um[tmp] == 1) return false;
		else {
			um[phone_book[i]]++;
		}
	}
	return answer;

}

void main() {

	vector<string> v;
	v.push_back("111113");
	v.push_back("1112");
	v.push_back("12");
	v.push_back("119");
	solution(v);
}
