#include <stdio.h>
#include <stdlib.h>

//int arr[100001][100001] = {0}; 

int count = 1; 
// 스택: 배열
// 그래프: 이차원 배열
// 이것도 메모리 초과...
// 도대체 어떻게 풀어야 하는 거지??

void heap_sort(int *heap, int size) {
	int child = size; 
	int parent = child / 2; 
	int temp; 

	// bubble up.
	while (child != 1) {
		if (heap[parent] > heap[child]) {
			temp = heap[parent]; 
			heap[parent] = heap[child]; 
			heap[child] = temp; 

			child = parent; 
			parent /= 2; 
		} else {
			break; 
		}
	}

}

void insertNumber(int **arr, int from, int to) {
	// printf("insertNumber\n"); 
	// 그래프는 양방향. 
	// 해당 배열의 힙에 원소 숫자가 insert 된 것.
	int size = ++arr[from][0];

	arr[from][size] = to; 
	// 오름차순으로 정렬
	heap_sort(arr[from], size); 

	arr[to][0]++; 
	size = arr[to][0];
	arr[to][size] = from; 
	heap_sort(arr[to], size); 

}

void deleteFirstNode(int *heap) {

	// printf("heap[0]: %d\n", heap[0]); 
	int size = heap[0];
	heap[0]--;  
	heap[1] = heap[size]; 

	int parent = 1; 
	int child = parent * 2; 

	int temp; 
	// bubble down. 
	while (child <= size) {
		if (child + 1 <= size && heap[child] > heap[child+1]) {
			child++; 
		}

		if (heap[parent] > heap[child]) {
			temp = heap[parent]; 
			heap[parent] = heap[child]; 
			heap[child] = temp; 

			parent = child; 
			child *= 2; 
		} else {
			break; 
		}
	}
}

void dfsSearch(int **arr, int start, int *visitedOrder, int *stack) {
	int size = 1; 
	int i; 

	while (size != 0) {
		i = stack[size]; 

		if (!arr[i][0]) {
			// 아무 원소가 없다면. 스택에서 숫자 제거. 
			size--; 

		} else {
			
			if (!visitedOrder[arr[i][1]]) {
				// 방문을 안했었더라면. 
				visitedOrder[arr[i][1]] = count++; 
				stack[++size] = arr[i][1]; 
			}

			deleteFirstNode(arr[i]); 

		}
		// printf("----\n"); 
		// for (int j= 1; j <= size; j++) {
		// 	printf("stack: %d\n", stack[j]); 
		// }

	}
}

int main()
{
	int N, M, R; 
	scanf("%d %d %d", &N, &M, &R); 

	// 동적 할당. 
	// int **arr = (int **)calloc(N+1, sizeof(int *)); 
	// for (int i = 0; i <= N; i++) {
	// 	arr[i] = (int *)calloc(N+1, sizeof(int)); 
	// }
	int **arr = (int **)calloc(N+1, sizeof(int *));
	int *visitedOrder = (int *)calloc(N+1, sizeof(int)); 
	int *stack = (int *)malloc(sizeof(int) * (N+1)); 

	visitedOrder[R] = count++;
	stack[1] = R; 
	// DFS 탐색 본격 시작. 
	int from, to; 
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to); 
		visitedOrder[from]++; 
		insertNumber(/*arr,*/ from, to);
	}




	// dfs 탐색. 
	dfsSearch(/*arr,*/ R, visitedOrder, stack); 

	for (int i = 1; i <= N; i++) {
		printf("%d\n", visitedOrder[i]); 
	}


	//메모리 해제. 
	// for (int i = 0; i <= N; i++) {
	// 	free(arr[i]); 
	// }
	// free(arr); 
	free(visitedOrder); 
	free(stack); 
	
}