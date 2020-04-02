#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string solution(string &S, string &C) {
	string now = "";
	string first = "";
	string last = "";
	string fullname = "";
	string email = "";
	string answer = "";
	string company = "";
	for (int j = 0; j < C.size(); j++) {
		company.append(1, tolower(C[j]));
	}
	bool check = false;
	int start = 0;
	int mid = 0;
	int end = 0;
	unordered_map<string, int> m;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ' ' && !check) {
			first.append(now);
			check = true;
			now = "";
			continue;
		}
		if (S[i] == ' ' && check) {
			now = "";
			continue;
		}
		if (S[i] == ';'|| i==S.size()-1) {
			if (i == S.size() - 1) {
				now.append(1, S[i]);
			}
			last.append(now);
			end = i; 
			if (i == S.size() - 1) {
				fullname.append(S, start, end - start+1);
			}
			else {
				fullname.append(S, start, end - start);
			}
			now = "";
			email = last +"_"+ first;
			m[email]++;
			if (m[email] == 1) {
				answer += fullname + " <"+email + "@" + company + ".com>";
			}
			else {
				answer += fullname + " <" + email + to_string(m[email]) + "@" + company + ".com>";
			}

			if (i != S.size() - 1) answer += "; ";
			first = "";
			last = "";
			now = "";
			fullname = "";
			email = "";
			check = false;
			start = i + 2;
			i++;
		}
		else {
			if (S[i] == '-') continue;
			now.append(1, tolower(S[i]));
		}

	}
	cout << answer;
	return answer;
}

int main() {
	string s = "Lee ji Eun; Park ji Sung; Park JI sung";
	string c = "example";
	solution(s, c);

	system("pause");
	return 0;
}