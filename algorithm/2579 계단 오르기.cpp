#include <iostream>
#include <algorithm>
using namespace std;

int arr[301][2] = { 0, }; //arr[i][0] = +1 , arr[i][1] = +2
int stair[301] = { 0, };
int check[301][2] = { 0, };
//1, 2 1+1+1(x)
//고민은 1+1 이후에 체크를 어떻게 할 것인가? 체크해주는 배열로?
//2+1+1(x)
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	arr[1][0] = stair[1];
	check[1][0]=1;
	arr[2][0] = arr[1][0] + stair[2];
	check[2][0] = check[1][0] + 1;
	arr[2][1] = stair[2];
	check[2][1] = 1;

	for (int j = 3; j <= n; j++) {
		arr[j][1] = max(arr[j - 2][0], arr[j - 2][1]) + stair[j];
		check[j][1] = 1;

		//2+1 => +1(x)
		if (check[j - 1][0] != 2) { // 1+1(x) => 2+1, ~+2, 1
			if (check[j - 1][0] == 1) { // 1
				if (check[j - 3][1] !=1) { // 2+1(x) 그냥 1만 있음
					arr[j][0] = arr[j - 1][0] + stair[j];
					check[j][0] = 2;
				}
			}
			else { // 2
					arr[j][0] = arr[j - 1][1] + stair[j];
					check[j][1] = 1;
			}
		}
		else { // 1+1 (x) 2 => +1
			if (check[j - 1][1] == 1) {
				arr[j][0] = arr[j - 1][1] + stair[j];
			}
		}
	}
	cout << max(arr[n][0], arr[n][1])<<"\n";
	system("pause");
	return 0;
}