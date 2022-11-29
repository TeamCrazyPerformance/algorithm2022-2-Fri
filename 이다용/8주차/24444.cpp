#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vii;
typedef vector<bool> vib;

vii V; 
vib visited;
vvi E;
int N, M, R, order = 1;
queue<int> Q;

void fastIO() {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
}

void init() {
	cin >> N >> M >> R;
	int u, v;
	V.resize(N + 1);
	visited.resize(N + 1,false);
	E.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(E[i].begin(), E[i].end());
	}
	visited[R] = true;
	V[R] = order++;
	Q.push(R);
}



int main() {
	fastIO();
	init();
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i : E[x]) {
			if (!visited[i]) {
				visited[i] = true;
				V[i] = order++;
				Q.push(i);
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << V[i] << "\n";
}
