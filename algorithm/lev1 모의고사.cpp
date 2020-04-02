#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr1[5] = { 1,2,3,4,5 };
int arr2[8] = { 2,1,2,3,2,4,2,5 };
int arr3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<pair<int, int>> v;
	v.push_back(make_pair(0, 1));
	v.push_back(make_pair(0, 2));
	v.push_back(make_pair(0, 3));
	int num = 1;
	for (int i = 0; i < answers.size(); i++) {
		if (arr1[i % 5] == answers[i]) {
			v[0].first++;
		}
		if (arr2[i % 8] == answers[i]) {
			v[1].first++;
		}
		if (arr3[i % 10] == answers[i]) {
			v[2].first++;
		}
	}
	//int they_max = *max_element(they.begin(), they.end());
	sort(v.begin(), v.end());
	int max_num = 0;
	for (int l = 0; l < 3; l++) {
		if (v[l].first > 0 && v[l].first == v[2].first) {
			answer.push_back(v[l].second);
		}
	}
	return answer;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	solution(a);

	return 0;
}