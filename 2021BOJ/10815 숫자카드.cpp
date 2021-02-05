#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int n,m,arr1[500001],y;
int main() {

	vector<int> vt;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
		vt.push_back(arr1[i]);
	}
	sort(vt.begin(), vt.end());
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &y);
		printf("%d ", binary_search(vt.begin(), vt.end(), y));

	}

}
