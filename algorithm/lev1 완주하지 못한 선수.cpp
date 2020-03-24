#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> m;
	for (int i = 0; i < participant.size(); i++) {
		m[participant[i]]++;
	}
	for (int j = 0; j < completion.size(); j++) {
		m[completion[j]]++;
	}
	for (auto it = m.begin(); it != m.end(); ++it) {
		if ((it->second) % 2 != 0) {
			return it->first;
		}
	}
}

void main() {
	vector<string> p;
	vector<string> c;
	p.push_back("le");
	p.push_back("ki");
	p.push_back("ed");
	c.push_back("ed");
	c.push_back("ki");
	solution(p, c);
}