#include <stdio.h>
#include <stdlib.h>

int maxOfHeight(int steps[], int dp[], int N) {

	dp[0] = steps[0]; 
	dp[1] = steps[0] + steps[1]; 

	for (int i = 2; i < N; i++) {
		dp[i] = steps[i];
		if (dp[i-3] + steps[i-1] > dp[i-2]) {
			dp[i] += dp[i-3] + steps[i-1];
		} else {
			dp[i] += dp[i-2]; 
		}
	}

	return dp[N-1]; 
}

int main()
{
	int N, num; 
	scanf("%d", &N); 

	int *steps = (int *)malloc(sizeof(int) * N); 
	int *dp = (int *)malloc(sizeof(int) * N); 

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		steps[i] = num;  
	}

	int result = maxOfHeight(steps, dp, N); 

	printf("%d\n", result);

	free(steps); free(dp); 
}