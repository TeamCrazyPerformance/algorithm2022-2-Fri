#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scores[300], dp[300] = {};

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> scores[i];
	
	dp[0] = scores[0];
	dp[1] = scores[0] + scores[1];
	dp[2] = max(scores[0] + scores[2], scores[1] + scores[2]);
	for(int i = 3; i < n; i++)
		dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]);
	
	cout << dp[n - 1];
	
	return 0;
}
