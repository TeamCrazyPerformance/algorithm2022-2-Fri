#include <stdio.h>
#include <stdlib.h>

int count = 1; 

typedef struct _fromTo {
	int from; 
	int to;
} fromTo; 

void heap_sort(int *heap, int index) {
	int child = index; 
	int parent = child / 2; 
	int temp; 

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

void insertNumbers(int **arr, int from, int to) {

	int size = ++arr[from][0]; 
	arr[from][size] = to; 

	heap_sort(arr[from], size); 
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
		if (arr[i] == NULL || arr[i][0] == 0) {
			// 아무 원소가 없다면. 스택에서 숫자 제거. 
			size--; 
		} else {
			if (visitedOrder[arr[i][1]] == 0) {
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

	int *sizeArr = (int *)calloc(N+1, sizeof(int));
	// from, to 정보를 담은 구조체 배열. 
	fromTo *nodes = (fromTo *)malloc(sizeof(fromTo) * (M+1)); 

	int from, to; 
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to); 
		sizeArr[from]++; 
		sizeArr[to]++;  
		nodes[i].from = from; 
		nodes[i].to = to; 
	}

	// 메모리 할당. 
	int **arr = (int **)calloc(N+1, sizeof(int *));
	for (int i = 1; i <= N; i++) {
		if (sizeArr[i] != 0) {  // 문제 발견. 조건을 !sizeArr[i] 로 하면 왜 안될까? 
			arr[i] = (int *)calloc(sizeArr[i] + 1, sizeof(int));
		}
	} 
	free(sizeArr);


	// 힙 정렬을 하면서 숫자 insert.  
	for (int i = 1; i <= M; i++) {
		from = nodes[i].from;
		to = nodes[i].to; 
		//printf("from: %d to: %d\n", from, to); 
		insertNumbers(arr, from, to); 
		insertNumbers(arr, to, from); 
	}

	free(nodes);

	// DFS 탐색 시작. 
	int *visitedOrder = (int *)calloc(N+1, sizeof(int)); 
	int *stack = (int *)calloc(N+1, sizeof(int)); 
	visitedOrder[R] = count++;
	stack[1] = R; 
	
	dfsSearch(arr, R, visitedOrder, stack); 
	//printf("-----\n");
	// for (int i = 1; i <= N; i++) {
	// 	if (arr[i] == NULL) continue;
	// 	for (int j = 0; j <= arr[i][0]; j++) {
	// 		printf("%d ", arr[i][j]);
	// 	}
	// 	printf("\n"); 
	// }

	for (int i = 1; i <= N; i++) {
		printf("%d\n", visitedOrder[i]);
	}
	//메모리 해제. 
	for (int i = 1; i <= N; i++) {
		if (arr[i] != NULL) {
			free(arr[i]); 
		}
	}
	free(arr); free(visitedOrder); 

}