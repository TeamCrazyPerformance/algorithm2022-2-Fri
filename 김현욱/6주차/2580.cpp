#include <iostream>
#include <vector>

#define LINE_SIZE 9

using namespace std;

int board[LINE_SIZE][LINE_SIZE];
vector<pair<int, int>> emptys;

bool checkRow(int x, int num) {
	for(int i = 0; i < LINE_SIZE; i++)
		if(board[x][i] == num)
			return false;
	return true;
}

bool checkColumn(int y, int num) {
	for(int i = 0; i < LINE_SIZE; i++)
		if(board[i][y] == num)
			return false;
	return true;
}

bool checkSquare(int x, int y, int num) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(board[x - (x % 3) + i][y - (y % 3) + j] == num)
				return false;
		}
	}
	return true;
}

void sudoku(int pos) {
	if (pos == emptys.size()) {
		for(int i = 0; i < LINE_SIZE; i++) {
			for(int j = 0; j < LINE_SIZE; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
		
		exit(0);
	
		return;
	}
		
	int x = emptys[pos].first;
	int y = emptys[pos].second;
	
	for (int num = 1; num <= 9; num++) {
		if (checkRow(x, num) && checkColumn(y, num) && checkSquare(x, y, num)) {
			board[x][y] = num;
			sudoku(pos + 1);
			board[x][y] = 0;
		}
	}
}

int main() {
	for(int i = 0; i < LINE_SIZE; i++) {
		for(int j = 0; j < LINE_SIZE; j++) {
			cin >> board[i][j];
			if(board[i][j] == 0)
				emptys.push_back(make_pair(i, j));
		}
	}
			
	sudoku(0);
	
	return 0;
}
