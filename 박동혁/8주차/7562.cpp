#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int cnt[301][301];
int l, x, y, n, m;
void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    int dx[8]={2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8]={1, -1, 1, -1, 2, -2, 2, -2};
    while(!q.empty()) {
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0; i<8; i++) {
            int new_x = x+dx[i], new_y = y+dy[i];
            if(new_x < 0 || new_y < 0 || new_x >= l || new_y >= l) continue;
            if(cnt[new_x][new_y] == 0) {
                q.push(make_pair(new_x, new_y));
                cnt[new_x][new_y] = cnt[x][y]+1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> l >> x >> y >> n >> m;
        if(x==n && y==m) {
            cout << 0 << '\n';
            continue;
        }
        bfs();
        cout << cnt[n][m] << '\n';
        memset(cnt, 0, sizeof(cnt));
    }
}