#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> um;
	vector<int> v;
	for (int i = 0; i < clothes.size(); i++) {
		um[clothes[i][1]]++;
	}
	for (auto iter = um.begin(); iter != um.end(); ++iter) {
		v.push_back(iter->second);
	}
	for (int j = 0; j < v.size(); j++) {
		answer *= (v[j] + 1);
	}

	return answer-1;
}