#include <stdio.h>
#include <stdlib.h>
int flag = 0;
int max = 0;  

// 처음으로 재귀함수 써서 원하는 결과를 얻어 내는데 성공하였지만...
// 시간 초과가 난다. 
// 데이터 수가 300개면 재귀함수를 쓰기에는 너무 많나????
int maxHeight(int steps[], int i, int sumOfHeight) {

	if (i < 0) {
		if (sumOfHeight > max) {
			max = sumOfHeight;
		}
		return max;
	} 
	sumOfHeight += steps[i]; 

	if (flag) {  // 이전 계단을 밟았다면, 반드시 계단을 건너 뛰어 밟아야 함.
		flag = 0; 
		i -= 2; 
		return maxHeight(steps, i, sumOfHeight);
	}  else {
		//계단을 하나 건너 뜀. 
		flag = 1; 
		i--; 
		maxHeight(steps, i, sumOfHeight);

		//계단을 두 개 건너 뜀.
		flag = 0; 
		i--;
		return maxHeight(steps, i, sumOfHeight); 
	}

}

int main()
{
	int N, height; 
	scanf("%d", &N); 

	int *steps = (int *)malloc(sizeof(int) * N); 
	for (int i = 0; i < N; i++) {
		scanf("%d", &height);
		steps[i] = height; 
	}

	int result = maxHeight(steps, N-1, 0); 
	printf("%d\n", result); 

	free(steps); 
}