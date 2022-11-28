#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int visited[100001];
vector<int> graph[100001];
int cnt;
void dfs(int num)
{
    visited[num] = ++cnt;
    for(int i=0; i<graph[num].size(); i++) {
        if(visited[graph[num][i]]!=0) continue;
        dfs(graph[num][i]);
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
    
    dfs(r);
    for(int i=1; i<=n; i++) {
        cout << visited[i] << '\n';
    }
}