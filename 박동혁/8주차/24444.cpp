#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int visited[100001];
vector<int> graph[100001];
int cnt;
void bfs(int r)
{
    queue<int> q;
    q.push(r);
    visited[r] = ++cnt;
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        for(int i=0; i<graph[num].size(); i++) {
            if(visited[graph[num][i]]!=0)
                continue;
            q.push(graph[num][i]);
            visited[graph[num][i]] = ++cnt;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
        sort(graph[i].begin(), graph[i].end());
    
    bfs(r);
    for(int i=1; i<=n; i++) {
        cout << visited[i] << '\n';
    }
}