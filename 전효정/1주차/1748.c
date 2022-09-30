// <수 이어쓰기1>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// int main()
// {
// 	int N, lenOfInt, result = 0;

// 	char str[10];
// 	scanf("%d", &N);
// 	for (int i = 1; i <= N; i++) {
// 		sprintf(str, "%d", i);
// 		lenOfInt = strlen(str);

// 		result += lenOfInt;
// 	}
// 	printf("%d\n", result);
// }
int main()
{
	int len, N, result = 0;
	char str[20];
	scanf("%d", &N);
	sprintf(str, "%d", N);
	len = strlen(str);

	int n = len-1;

	for (int i = 1; i <= n; i++) {
		result += i * 9 * pow(10, i-1);
	}

	result += len * (N - pow(10, n) + 1);

	printf("%d", result);


}
