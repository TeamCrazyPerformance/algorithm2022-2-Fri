#include <iostream>
using namespace std;

int N, answer = 0, board[14];

bool check(int pos) {
	for(int i = 0; i < pos; i++)
        if(board[i] == board[pos] || abs(board[pos] - board[i]) == pos - i)
            return false;
    return true;
}

void nqueen(int pos) {
	if(pos == N)
		answer++;
	else {
		for(int i = 0; i < N; i++) {
			board[pos] = i;
			if(check(pos))
				nqueen(pos + 1);
		}
	}
}

int main() {
	cin >> N;
	nqueen(0);
	cout << answer;
	return 0;
}
