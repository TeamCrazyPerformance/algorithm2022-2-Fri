#include<iostream>

using namespace std;

int dp[1100][1100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int arr[1100][1100];
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(j==1) {
                dp[i][1] = dp[i-1][1] + arr[i][1];
                dp[1][i] = dp[1][i-1] + arr[1][i];
            } else {
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + arr[i][j]; 
                dp[j][i] = dp[j-1][i] + dp[j][i-1] - dp[j-1][i-1] + arr[j][i];
            }
        }
    }
    int x1, y1, x2, y2;
    while(m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }
}