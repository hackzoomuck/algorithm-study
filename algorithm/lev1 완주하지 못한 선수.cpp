#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < participant.size(); i++) {
		if (participant[i] != completion[i]) {
			answer = participant[i];
			return answer;
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