#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _RGB {
	int rgb[3];
	// index 0: red, index 1: green, index 2: blue
} RGB;


int RGB_dp(RGB rgbArray[], int N, int dp[]) {
	int *indexes = (int *)malloc(sizeof(int) * N); 

	int min = INT_MAX; 
	// 이 부분이 오류일 것 같아.
	// 초깃값 설정에서.
	int min0 = INT_MAX, min1 = INT_MAX, min2 = INT_MAX; 
	int minI, minJ, minK; 

	int minOftwo = INT_MAX; 
	// 아...! N = 2 일 땐 어뜩할래?
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (i == j) continue; 

			if (rgbArray[0].rgb[i] + rgbArray[1].rgb[j] < minOftwo) {
				minOftwo = rgbArray[0].rgb[i] + rgbArray[1].rgb[j];
			}
		}
	}

	if (N == 2) return minOftwo; 

	for (int i = 0; i <= 2; i++) {
		if (rgbArray[0].rgb[i] < min0) {
	 		min0 = rgbArray[0].rgb[i]; 
	 		minI = i; 
		}
		for (int j = 0; j <= 2; j++) {
			if (i == j) continue; 
			if (rgbArray[0].rgb[i] + rgbArray[1].rgb[j] < min1) {
				min1 = rgbArray[0].rgb[i] + rgbArray[1].rgb[j]; 
				minJ = j; 
			}
			for (int k = 0; k <= 2; k++) {
				if (j == k) continue; 
				if ( (rgbArray[0].rgb[i] + rgbArray[1].rgb[j] + rgbArray[2].rgb[k]) < min2) {
					min2 = rgbArray[0].rgb[i] + rgbArray[1].rgb[j] + rgbArray[2].rgb[k];
					minK = k; 
				}
			}
		}
	}
	// // dp[0] 과 dp[1] 과 dp[2] 를 먼저 계산함. 
	dp[0] = min0; indexes[0] = minI; 
	dp[1] = min1; indexes[1] = minJ; 
	dp[2] = min2; indexes[2] = minK; 

	if (N == 3) return dp[2]; 
 	
	// dp[i] = dp[i-2] + minValue[i]
	for (int index = 3; index < N; index++) {
		min = INT_MAX;  
		indexes[index] = 0; 
		for (int i = 0; i <= 2; i++) {
			if (indexes[index-3] == i) continue; 
			for (int j = 0; j <= 2; j++) {
				if (i == j) continue; 
	
				for (int k = 0; k <= 2; k++) {
					if (j == k) continue; 

					if ( (rgbArray[index-2].rgb[i] + rgbArray[index-1].rgb[j] + rgbArray[index].rgb[k]) < min) {
						min = rgbArray[index-2].rgb[i] + rgbArray[index-1].rgb[j] + rgbArray[index].rgb[k];
						//printf("i: %d j: %d k: %d\n", i, j, k); 

						indexes[index] = i; 
					}
				}
			}
		}
		dp[index] = dp[index-3] + min;
	}

	// for (int i = 0; i < N; i++) {
	// 	printf("dp[%d]: %d\n", i, dp[i]); 
	// }

	free(indexes); 
	return dp[N-1];
}

int main()
{
	int N, R, G, B;
	scanf("%d", &N); 
	RGB *rgbArray = (RGB *)malloc(sizeof(RGB) * N); 
	int *dp = (int *)calloc(N, sizeof(int)); 

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &R, &G, &B); 
		rgbArray[i].rgb[0] = R;
		rgbArray[i].rgb[1] = G; 
		rgbArray[i].rgb[2] = B; 
	}

	int result = RGB_dp(rgbArray, N, dp); 

	printf("%d\n", result);

	free(rgbArray); free(dp); 
}