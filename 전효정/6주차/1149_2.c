#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) ( (x) < (y) ? (x) : (y))

int minCost(int **houses, int **dp, int N) {
	dp[0][0] = houses[0][0]; 
	dp[0][1] = houses[0][1];
	dp[0][2] = houses[0][2]; 

	for (int i = 1; i < N; i++) {
		dp[i][0] = houses[i][0] + ( MIN(dp[i-1][1], dp[i-1][2]) ); 
		dp[i][1] = houses[i][1] + ( MIN(dp[i-1][0], dp[i-1][2]) ); 
		dp[i][2] = houses[i][2] + ( MIN(dp[i-1][0], dp[i-1][1]) );
	}

	return MIN(MIN(dp[N-1][0], dp[N-1][1]), dp[N-1][2]); 
}

int main()
{
	int N;
	scanf("%d", &N); 

	int **houses = (int **)malloc(sizeof(int *) * N);
	int **dp = (int **)calloc(N, sizeof(int *)); 
 
	for (int i = 0; i < N; i++) {
		houses[i] = (int *)malloc(sizeof(int) * 3);
		dp[i] = (int *)calloc(3, sizeof(int));  
	}

	int r, g, b; 
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &r, &g, &b); 
		houses[i][0] = r; 
		houses[i][1] = g; 
		houses[i][2] = b; 
	}

	int result = minCost(houses, dp, N); 
	printf("%d\n", result);

	for (int i = 0; i < N; i++) {
		free(houses[i]); 
		free(dp[i]); 
	}
	free(houses); free(dp); 
}