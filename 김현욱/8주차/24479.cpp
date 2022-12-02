#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_COUNT 100001

using namespace std;

int N, M, R, u, v, _count = 0;
vector<vector<int>> graph(MAX_COUNT);
vector<bool> visited(MAX_COUNT);
vector<int> answer(MAX_COUNT);

void dfs(int R) {
	if(visited[R])
		return;
	
	visited[R] = true;
	_count++;
	answer[R] = _count;
	
	for (int i = 0; i < graph[R].size(); i++)
		dfs(graph[R][i]);
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
		
	dfs(R);
	
	for(int i = 1; i <= N; i++)
		cout << answer[i] << "\n";
	
	return 0;
}