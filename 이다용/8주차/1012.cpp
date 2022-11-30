#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int worm;
int T, M, N, K;
vector<vector<bool>> V;
vector<pair<int, int>> P;
queue < pair<int, int>> Q;

void fastIO() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
}

void init() {
	cin >> M >> N >> K;
	V.clear();
	V.resize(N, vector<bool>(M, false));
	P.clear();
	int X, Y;
	worm = 0;
	for (int j = 0; j < K; j++) {
		cin >> X >> Y;
		V[Y][X] = true;
		P.push_back({ Y,X });
	}
}


int main() {
	fastIO();
	cin >> T;
	for (int i = 0; i < T; i++) {
		init();
		while (!P.empty()) {
			
			worm++;
			Q.push(P[0]);
			V[P[0].first][P[0].second] = false;
			while (!Q.empty()) {
				int y = Q.front().first, x = Q.front().second;
				Q.pop();
				P.erase(remove(P.begin(), P.end(), make_pair(y, x)), P.end());
				if (y > 0 && V[y - 1][x]) {
					V[y - 1][x] = false;
					Q.push({ y - 1,x });
				}
				if (x > 0 && V[y][x - 1]) {
					V[y][x - 1] = false;
					Q.push({ y,x - 1 });
				}
				if (y < N - 1 && V[y + 1][x]) {
					V[y + 1][x] = false;
					Q.push({ y + 1,x });
				}
				if (x < M - 1 && V[y][x + 1]) {
					V[y][x + 1] = false;
					Q.push({ y ,x + 1 });
				}
			}
		}
		cout << worm << "\n";
	}
}
