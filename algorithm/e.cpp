#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int section_size = 0;
vector<int> v;

void dfs(int **m, int x, int y, int size_m) {
	section_size++;
	m[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= size_m || ny < 0 || ny >= size_m) continue;
		if (m[nx][ny]) {
			dfs(m, nx, ny, size_m);
		}
	}
}

void solution(int sizeOfMatrix, int **matrix) {
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			if (matrix[i][j]) {
				section_size = 0;
				dfs(matrix, i, j, sizeOfMatrix);
				v.push_back(section_size);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	if (!v.size()) return;
	for (int j = 0; j < v.size(); j++) {
		cout << v[j]<<" ";
	}
	cout << "\n";
}

struct input_data {
	int sizeOfMatrix;
	int **matrix;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.sizeOfMatrix;

	inputData.matrix = new int*[inputData.sizeOfMatrix];
	for (int i = 0; i < inputData.sizeOfMatrix; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.matrix[i] = new int[inputData.sizeOfMatrix];
		for (int j = 0; j < inputData.sizeOfMatrix; j++) {
			iss >> inputData.matrix[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.sizeOfMatrix, inputData.matrix);
	
	system("pause");
	return 0;
}