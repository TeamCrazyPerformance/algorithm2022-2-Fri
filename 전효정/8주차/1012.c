#include <stdio.h>
#include <stdlib.h>

// 런타임 에러 (Segfault) 가 왜 나는 걸까??

typedef struct _coordinate {
	int x;
	int y;
} Coor;

int howManyWorms(int graph[][100], Coor *queue, 
	Coor *ones, int M, int N, int K) {
	
	int count = 0; 
	int front = 0, rear = 1;

	int i, j;
	int index = 0;

	// printf("====\n"); 
	// for (int i = 0; i < K; i++) {
	// 		printf("ones: %d %d\n", ones[i].x, ones[i].y); 
	// }
	// for (int i = 0; i < M; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		printf("%d ", [i][j]); 
	// 	}
	// 	printf("\n"); 
	// }

	while (index < K) { // 조건이 이게 맞는지 다시 한 번 생각해 볼 것. 
		if (graph[ones[index].x][ones[index].y] == 0) {
			index++;
			continue; 
		}
		count++; 
		front = 0; rear = 1;
		queue[front].x = ones[index].x;
		queue[front].y = ones[index].y;

		while (front < rear) {
			// printf("=====queue=====\n"); 
			// for (int t = front; t < rear; t++) {
			// 	printf("%d %d\n", queue[t].x, queue[t].y); 
			// }
			// printf("\n");
			i = queue[front].x;
			j = queue[front].y;
			if (i >= M || j >= N) {
				front++; 
				continue;
			}
			// ====================
			// 백준 게시판 djm03178 님의 의견:
			// BFS를 할 때에는 큐에서 뺀 뒤가 아닌, 큐에 넣을 때 방문 표시를 해야
			// 중복 방문이 일어나지 않습니다.
			graph[i][j] = 0; 
			// ====================
			front++;
			if (i-1 >= 0 && graph[i-1][j] == 1) {
				// 위에도 배추가 있다면. 
				//printf("UP\n");

				//--------------------
				graph[i-1][j] = 0; 
				//--------------------
				queue[rear].x = i-1;
				queue[rear].y = j; 
				rear++; 
			}
			if (i+1 < M && graph[i+1][j] == 1) {
				// 아래에도 배추가 있다면. 
				//printf("DOWN\n"); 
				//--------------------
				graph[i+1][j] = 0; 
				//--------------------
				queue[rear].x = i+1;
				queue[rear].y = j; 
				rear++; 
			}
			if (j+1 < N && graph[i][j+1] == 1) {
				// 오른쪽에도 배추가 있다면.
				//printf("RIGHT\n");
				//---------------------
				graph[i][j+1] = 0;  
				//---------------------
				queue[rear].x = i; 
				queue[rear].y = j+1;
				rear++; 
			}
			if (j-1 >= 0 && graph[i][j-1] == 1) {
				// 왼쪽에도 배추가 있다면. 
				//printf("LEFT\n"); 
				//---------------------
				graph[i][j-1] = 0; 
				//---------------------
				queue[rear].x = i; 
				queue[rear].y = j-1; 
				rear++; 
			}	

			// printf("i: %d j: %d\n", i, j); 
			// printf("front: %d rear: %d\n", front, rear);
			// printf("count: %d\n", count);  

		}
		index++; 
	}

	return count; 
}

int main()
{
	int T; 
	scanf("%d", &T);  

	int *result = (int *)malloc(sizeof(int) * T); 

	int M, N, K;
	int x, y; 	

	int worms; 
	int p = 0;

	int graph[100][100] = {0}; 
	Coor queue[100000]; 
	Coor ones[100000];

	while (p < T) {
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &x, &y); 
			graph[x][y] = 1; 
			ones[i].x = x; 
			ones[i].y = y; 			
		}
		worms = howManyWorms(graph, queue, ones, M, N, K); 
		result[p++] = worms; 
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", result[i]);
	}
	free(result); 
}