#include <iostream>
#include <sstream>

using namespace std;

char arr[28];
int cnt[28];

bool isfast(int quicksize, char *quickplayer, int idx) {
	for (int i = 0; i < quicksize; i++) {
		if (quickplayer[i] == arr[idx]) {
			return true;
		}
	}
	return false;
}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {

	int s_mod = numOfAllPlayers - 1;
	for (int i = 0; i < s_mod; i++) {
		arr[i] = 'A' + i + 1;
	}
	int sulrae = 0;
	char csulrae = 'A';
	cnt[sulrae]++;
	for (int j = 0; j < numOfGames; j++) {
		int s_turn = (numOfMovesPerGame[j]) % s_mod;
		sulrae = (sulrae + s_turn + s_mod) % s_mod;
		if (!isfast(numOfQuickPlayers, namesOfQuickPlayers, sulrae)) {//turn : change sulrae

			char tmp = csulrae;
			csulrae = arr[sulrae];
			arr[sulrae] = tmp;
		}
		int sidx = csulrae - 'A';
		cnt[sidx]++;
	}
	for (int k = 0; k < s_mod; k++) {
		cout << arr[k] << " " << cnt[arr[k] - 'A'] << "\n";
	}
	char c = 'A' + sulrae + 1;
	cout << csulrae << " " << cnt[csulrae - 'A'] << "\n";
}

struct input_data {
	int numOfAllPlayers;
	int numOfQuickPlayers;
	char *namesOfQuickPlayers;
	int numOfGames;
	int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfAllPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfQuickPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
	for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
		iss >> inputData.namesOfQuickPlayers[i];
	}

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfGames;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.numOfMovesPerGame = new int[inputData.numOfGames];
	for (int i = 0; i < inputData.numOfGames; i++) {
		iss >> inputData.numOfMovesPerGame[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
	system("pause");
	return 0;
}