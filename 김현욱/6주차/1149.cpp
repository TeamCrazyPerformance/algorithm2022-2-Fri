#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, r, g, b, dp[3][1001] = {};
	cin >> N;
	
	for(int i = 1; i <= N; i++) {
		cin >> r >> g >> b;
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + r;
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + g;
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + b;
	}
	
	cout << min(dp[0][N], min(dp[1][N], dp[2][N]));
	
	return 0;
}
