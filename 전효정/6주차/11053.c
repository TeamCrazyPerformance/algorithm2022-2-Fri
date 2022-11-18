#include <stdio.h>
#include <stdlib.h>

int longestSequence(int dp[], int num, int max) {
	int i = max;

	if (num > dp[max]) {
		dp[++max] =  num;
	} else if (num <= dp[max]) {
		while (num <= dp[i-1] && i > 1) {
			i--;
		}
		dp[i] = num; 
	}
	// for (int i = 1; i <= max; i++) {
	// 	printf("dp[%d]: %d ", i, dp[i]); 
	// }
	// printf("\n"); 
	return max; 
}

int main()
{
	int N;
	scanf("%d", &N); 
	//dp의 index는 수들의 count된 값을 의미함. 
	int *dp = (int *)calloc(N+2, sizeof(int)); 
	//해당 index의 값은 해당 count를 가지는 최솟값임.

	int num;
	int max = 1;
	scanf("%d", &num); 
	dp[1] = num; 
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &num);
		max = longestSequence(dp, num, max); 
	}

	printf("%d\n", max);

	free(dp); 
}