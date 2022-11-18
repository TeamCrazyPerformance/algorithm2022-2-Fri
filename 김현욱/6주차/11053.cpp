#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, arr[1000] = {}, dp[1000] = {}, answer = 0;
	cin >> N;
	
	for(int i = 0; i < N; i++)
		cin >> arr[i];
		
	for(int i = 0; i < N; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}
	
	cout << answer;
	
	return 0;
}
