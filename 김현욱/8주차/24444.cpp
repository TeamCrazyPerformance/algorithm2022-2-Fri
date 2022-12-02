#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_COUNT 100001

using namespace std;

int N, M, R, u, v, _count = 0;
vector<vector<int>> graph(MAX_COUNT);
vector<bool> visited(MAX_COUNT);
vector<int> answer(MAX_COUNT);
queue<int> Q;

void bfs(int R) {
	if(visited[R])
		return;
		
	for(int i = 1; i <= N; i++)
		visited[R] = false;
	visited[R] = true;
	_count++;
	answer[R] = _count;
	Q.push(R);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < graph[u].size(); i++) {
			int _v = graph[u][i];
			if (!visited[_v]) {
				visited[_v] = true;
				_count++;
				answer[_v] = _count;
				Q.push(_v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;
	
	for(int i = 1; i <= M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);                                                                                                                                                                                                    
	}
	
	for(int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
		
	bfs(R);
	
	for(int i = 1; i <= N; i++)
		cout << answer[i] << "\n";
	
	return 0;
}