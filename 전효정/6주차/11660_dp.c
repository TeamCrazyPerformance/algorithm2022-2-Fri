#include <stdio.h>
#include <stdlib.h>

void cumSum(int **map, int num, int x, int y) {
	if (x == 1) { // 기준 칸이 모서리에 존재하는 이유 
		map[x][y] = num + map[x][y-1]; 
	} else if (y == 1) {
		map[x][y] = num + map[x-1][y];
	} else {
		// 점화식
		map[x][y] = num + (map[x][y-1] + map[x-1][y] - map[x-1][y-1]);
	}
}

int main()
{
	int N, M; 
	scanf("%d %d", &N, &M);

	// 만약 동적할당이 제대로 안되면, 전역 변수로 설정해 보자. 
	int **map = (int **)malloc(sizeof(int *) * (N+1));
	//int **arr = (int **)malloc(sizeof(int *) * (N+1)); 
	for (int i = 0; i <= N; i++) {
		map[i] = (int *)malloc(sizeof(int) * (N+1));
		//arr[i] = (int *)malloc(sizeof(int) * (N+1));  
	}

	int num; 
	// cumulative sum - 누적합. 
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			scanf("%d", &num); 
			cumSum(map, num, x, y);
		}
	}

	int x1, y1, x2, y2;
	int result;  
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
		// 결과값 공식. 
		result = map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];
		printf("%d\n", result);
	}


	// 할당된 메모리 해제. 
	for (int i = 0; i <= N; i++) {
		free(map[i]); //free(arr[i]); 
	} 
	free(map); //free(arr); 

}