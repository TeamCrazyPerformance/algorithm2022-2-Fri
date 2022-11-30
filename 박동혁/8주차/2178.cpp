#include<iostream>
#include<queue>

using namespace std;

string maze[101];
int cnt[101][101];
void bfs(int x, int y)
{
    cnt[x][y]=1;
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()) {
        int x=q.front().first, y=q.front().second;
        q.pop();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int i=0; i<4; i++) {
            int new_x=x+dx[i], new_y=y+dy[i];
            if(new_x < 0 || new_y < 0) continue;
            if(maze[new_x][new_y]=='1' && cnt[new_x][new_y]==0) {
                q.push(make_pair(new_x, new_y));
                cnt[new_x][new_y]=cnt[x][y]+1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> maze[i];
    }
    bfs(0,0);
    cout << cnt[n-1][m-1];
}

// DFS 시간초과
/*
string maze[101];
bool visited[101][101];
int cnt, n, m, minn=100000;
void dfs(int x, int y)
{
    visited[x][y] = true;
    ++cnt;
    if(x==n-1 && y==m-1) {
        minn = (cnt < minn) ? cnt : minn;
        return;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for(int i=0; i<4; i++) {
        int new_x=x+dx[i], new_y=y+dy[i];
        if(new_x < 0 || new_y < 0) continue;
        if(maze[new_x][new_y]=='1' && !visited[new_x][new_y]) {
            dfs(new_x, new_y);
            visited[new_x][new_y] = false;
            cnt--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> maze[i];
    }
    dfs(0,0);
    cout << minn;
}
*/