#include <stdio.h>

int main()
{
	int  n, prev1, prev2, fib;
	scanf("%d", &n);

	if (n==0) fib = 0;
	else if (n==1) fib = 1;
	else if (n==2) fib = 1; 
	else {
		prev1 = 1, prev2 = 1;
		for (int i = 3; i <= n; i++) {
			fib = prev1 + prev2; 
			prev1 = prev2;
			prev2 = fib; 
		}
	}

	printf("%d\n", fib);
}