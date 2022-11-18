
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi board(10, vi(10));
vector<pair<int,int>> blank;
int g_N;
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

void init() {
	int node;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> node;
			board[i][j]=node;
			if (node == 0) blank.push_back({ i,j });
		}
	}
	g_N = blank.size();
}

void backTracking(int M) {
	if (M==g_N) {

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << board[i][j]<<" ";
			}
			cout << "\n";
		}
		cout << "\n";
		exit(0);
	}

	else {
		pair<int, int> F = blank[M];
		for (int i = 1; i <= 9; i++) {
			if (find(board[F.first].begin(), board[F.first].end(), i) != board[F.first].end()) continue;

			bool col_flag = false;
			for (int j = 1; j <= 9; j++) {
				if (board[j][F.second] == i)
				{
					col_flag = true;
					break;
				}
			}
			if (col_flag) continue;

			bool blk_flag = false;
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= 3; k++) {
					if (board[(F.first - 1) / 3 * 3 + j][(F.second - 1) / 3 * 3 + k] == i) {
						blk_flag = true;
						break;
					}
				}
				if (blk_flag)break;
			}
			if (blk_flag) continue;
			board[F.first][F.second] = i;
			backTracking(M+1);
			board[F.first][F.second] = 0;
		}
	}
}

int main() {
	fastIO();
	init();
	backTracking(0);
}
