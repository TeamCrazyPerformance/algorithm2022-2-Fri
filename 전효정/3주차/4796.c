#include <stdio.h>

int main()
{
	int L, P, V, turn= 1, result;
	while (1) {

		scanf("%d %d %d", &L, &P, &V);

		if (L == 0 && P == 0 && V == 0) break;

		result = V/P * L;

		if ( V-P*(V/P) < L ) {  // V - P*(V/P) 는 남은 일수.
			result += V-P*(V/P);
		} else {
			result += L;
		}
		printf("Case %d: %d\n", turn, result); 
		turn++;
	}

	return 0;
}