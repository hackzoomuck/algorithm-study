#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> minpq;
	priority_queue<int, vector<int>, less<int>> maxpq;
	int incnt = 0;
	int mincnt = 0;
	int maxcnt = 0;

	for (int i = 0; i < operations.size(); i++) {
		int tmpNum;
		string tmpString = "";
		switch (operations[i][0]) {
		case 'I':
			tmpString=operations[i].substr(2);
			tmpNum = stoi(tmpString);
			minpq.push(tmpNum);
			maxpq.push(tmpNum);
			incnt++;
			break;
		case 'D':
			if (operations[i][2] == '-' && !minpq.empty()){
				minpq.pop();
				mincnt++;
			}
			else if(!maxpq.empty()) {
				maxpq.pop();
				maxcnt++;
			}
			break;
		}
	}

	if (incnt > mincnt + maxcnt) {
		answer.push_back(maxpq.top());
		answer.push_back(minpq.top());
	}
	else {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}