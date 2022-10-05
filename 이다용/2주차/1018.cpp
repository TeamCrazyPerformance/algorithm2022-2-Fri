#include <iostream>
using namespace std;
#define MAX 51
int main() {
	int N, M;
	cin >> N >> M; int min = 51;
	char board[MAX][MAX];
	for (int i = 0; i < N; i++) cin >> board[i];
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8;j++) {
			int count = 0; int count1 = 0; int count2 = 0;
				for (int k = 0; k < 8; k++) {
					for (int s = 0; s < 4; s++) {
						if (k % 2 == 0 && board[i+k][j+2 * s + 1] != 'W') count1++;
						if (k % 2 == 1 && board[i+k][j+2 * s] != 'W') count1++;
						if (k % 2 == 0 && board[i+k][j+2 * s] != 'B') count1++;
						if (k % 2 == 1 && board[i+k][j+2 * s + 1] != 'B') count1++;
					}
				}
				for (int k = 0; k < 8; k++) {
					for (int s = 0; s < 4; s++) {
						if (k % 2 == 0 && board[i+k][j+2 * s + 1] != 'B') count2++;
						if (k % 2 == 1 && board[i+k][j+2 * s] != 'B') count2++;
						if (k % 2 == 0 && board[i+k][j+2 * s] != 'W') count2++;
						if (k % 2 == 1 && board[i+k][j+2 * s + 1] != 'W') count2++;
					}
				}
				if (count1 >= count2) { count = count2; }
				else { count = count1; }
			if (min > count) min = count;
		}
	}
	cout << min;
	return 0;
}
