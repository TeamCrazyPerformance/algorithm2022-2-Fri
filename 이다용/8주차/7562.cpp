#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INT_MAX 2147483647
using namespace std;

int T, I;
vector<vector<bool>> board;
vector<vector<int>> dist;
pair<int, int> st,ed;
queue<pair<int, int>> Q;

void fastIO() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

void init() {
	board.clear();
	dist.clear();
	while (!Q.empty()) Q.pop();
	cin >> I;
	board.resize(I, vector<bool>(I, false));
	dist.resize(I, vector<int>(I, INT_MAX));
	cin >> st.first >> st.second;
	cin >> ed.first >> ed.second;
	Q.push(st);
	board[st.first][st.second] = true;
	dist[st.first][st.second] = 0;
}

void bfs() {

	int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
	int dy[] = { 2,1,-1,-2,2,1,-1,-2 };
	while (!Q.empty()) {
		int Y = Q.front().first;
		int X = Q.front().second;
		if (Y == ed.first && X == ed.second) {
			cout << dist[Y][X]<<"\n";
			break;
		}
		for (int i = 0; i < 8; i++) {
			int nextY = Y + dy[i];
			int nextX = X + dx[i];
			if (nextY >= 0 && nextY < I && nextX >= 0 && nextX < I && board[nextY][nextX] == false) {
				Q.push({ nextY,nextX });
				board[nextY][nextX] = true;
				dist[nextY][nextX] = dist[Y][X] + 1;
			}
		}
		Q.pop();
	}
}

int main() {
	fastIO();
	cin >> T;
	for (int i = 0; i < T; i++) {
		init();
		bfs();
	}

}
