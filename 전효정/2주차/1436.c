#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int count;

int checkR(int i) {
	if (i <= 0) return 0;
	if (i % 1000 == 666) return 1;
	else checkR(i / 10);
}

int main(void) {
	scanf("%d", &N);

	for (int i = 666; i < 3000000; i++) {
		if (checkR(i)) count++;

		if (count == N) {
			printf("%d", i);
			break;
		}
	}
}