#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][10001] = { 0, };
int n, t;
vector<pair<int, int>> input;

int knapsack(int index, int capacity) {
	if (index == n) return 0;
	int max_value = dp[index][capacity];
	if (max_value != 0)return max_value;
	if (input[index].first <= capacity) {
		max_value = knapsack(index + 1, capacity - input[index].first) + input[index].second;
	}
	max_value = max(max_value, knapsack(index + 1, capacity));
	return max_value;
}

int main() {
	int k, s;
	int max_value = 0;
	cin >> n >> t;

	for (int a = 0; a < n; a++) {
		cin >> k >> s;
		input.push_back(make_pair(k, s));
	}
	cout << knapsack(0, t) << "\n";
	return 0;
}