#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> minpq; // minheap for using to delete min value
	priority_queue<int, vector<int>, less<int>> maxpq; // maxheap for using to delete max value

	for (int i = 0; i < operations.size(); i++) {// for loop : operations size
		int tmpNum; 
		string tmpString = "";
		switch (operations[i][0]) {
		case 'I':
			tmpString=operations[i].substr(2); // store substring(operations) from index 2 to end
			tmpNum = stoi(tmpString); // change string to int 
			minpq.push(tmpNum); 
			maxpq.push(tmpNum);
			break;
		case 'D':
			if (operations[i][2] == '-' && !minpq.empty()){
				minpq.pop();
			}
			else if(!maxpq.empty()) {
				maxpq.pop();
			}
			break;
		}
		// point!!! : these conditions mean that all element is deleted.
		if (maxpq.empty() || minpq.empty() || maxpq.top() < minpq.top()) {
			while (!maxpq.empty()) maxpq.pop();
			while (!minpq.empty()) minpq.pop();
		}
	}

	if (!maxpq.empty()) {
		answer.push_back(maxpq.top());
		answer.push_back(minpq.top());
	}
	else {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}
