//<별 찍기-5>

#include <stdio.h>

int main()
{
	int N, n;
	scanf("%d", &N);
	n = N-1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (n-i <= j && n+i >= j) printf("*");
			else if (n-i > j)printf(" ");
			else break;
		}
		printf("\n");
	}
}
