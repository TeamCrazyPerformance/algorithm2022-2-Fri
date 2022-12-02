#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> viI;
typedef vector<bool> viB;
int N, M, R, order=1;
viI V;
viB visited;
vvi E;


void fastIO(){
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
}

void init() {
	cin >> N >> M >> R;
	V.resize(N + 1);
	E.resize(N + 1);
	visited.resize(N + 1,false);
	visited[R] = true;
	V[R] = order++;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int x = 1; x <= N; x++) {
		sort(E[x].begin(), E[x].end());
	}

}

void dfs(int x) {
	for (int i: E[x] ) {
		if (!visited[i]) {
			V[i] = order++;
			visited[i] = true;
			dfs(i);
		}
	}
}

int main() {
	fastIO();
	init();
	dfs(R);
	for (int i = 1; i <= N; i++) cout << V[i] << "\n";
}
