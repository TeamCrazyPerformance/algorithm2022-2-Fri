//<홀수>

#include <stdio.h>

int main()
{
	int sum = 0, num, min = 200;

	for (int i = 0 ; i < 7; i++) {
		scanf("%d", &num);
		if (num % 2 == 1) {
			sum += num;
			if (num < min) min = num; 
		}
	}

	if (min == 200) printf("-1");
	else {
		printf("%d\n", sum);
		printf("%d", min);
	}
}
