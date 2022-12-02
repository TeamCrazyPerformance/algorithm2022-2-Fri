#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

short N, M;
vector<string> maze;
vector<vector<short>> dist;
queue<pair<short, short>> bfs;
short Y, X;

void fastIO() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

void init() {
	cin >> N >> M;
	maze.resize(N);
	dist.resize(N, vector<short>(M, 10000));
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}
	bfs.push({ 0,0 });
	maze[0][0] = '0';
	dist[0][0] = 1;
}

int main() {
	fastIO();
	init();
	while (!bfs.empty()) {
		Y = bfs.front().first;
		X = bfs.front().second;
		if (Y < N - 1 && maze[Y + 1][X] == '1'&& dist[Y + 1][X] > dist[Y][X] + 1) {
			bfs.push({ Y + 1,X });
			dist[Y + 1][X] = dist[Y][X]+1;
			maze[Y + 1][X] = '0';

		}
		if (Y > 0 && maze[Y - 1][X] == '1'&& dist[Y - 1][X] > dist[Y][X] + 1) {
			bfs.push({ Y - 1 ,X });
			dist[Y - 1][X] = dist[Y][X]+1;
			maze[Y - 1][X] = '0';

		}
		if (X < M - 1 && maze[Y][X + 1] == '1'&& dist[Y][X + 1] > dist[Y][X] + 1) {
			bfs.push({ Y , X + 1 });
			dist[Y][X + 1] = dist[Y][X]+1;
			maze[Y][X + 1] = '0';

		}
		if (X > 0 && maze[Y][X - 1] == '1'&& dist[Y][X - 1] > dist[Y][X] + 1) {
			bfs.push({ Y , X - 1 });
			dist[Y][X - 1] = dist[Y][X]+1;
			maze[Y][X - 1] = '0';

		}
		if (Y == N - 1 && X == M - 1) break;
		bfs.pop();
	}
	cout << dist[N - 1][M - 1];
}
