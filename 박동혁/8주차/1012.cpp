#include<iostream>
#include<cstring>

using namespace std;

int arr[51][51];
void dfs(int x, int y)
{
    arr[x][y]=2;
    if(arr[x+1][y]==1) dfs(x+1, y);
    if(arr[x-1][y]==1) dfs(x-1, y);
    if(arr[x][y+1]==1) dfs(x, y+1);
    if(arr[x][y-1]==1) dfs(x, y-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, m, n, k;
    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        for(int i=0; i<k; i++) {
            int a, b;
            cin >> a >> b;
            arr[a][b] = 1;
        }
        int cnt=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]==1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        memset(arr, 0, sizeof(arr));
    }
}