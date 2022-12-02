#include <stdio.h>
#include <stdlib.h>

int count = 1; 
int size = 0; 

// 왜 Segfault 가 계속 발생하는 걸까? 
// 하루종일 런타임 에러가 났었는데...
// 그 이유가 nodes 를 M+1 만큼이 아닌 N+1 개의 메모리만 할당해 주었기 때문이다. 

// 이걸 고쳤더니 이번에는 시간 초과. 

typedef struct _fromTo {
	int from; 
	int to; 
} fromTo;

void heap_sort(int *heap) {
	if (heap == NULL) return; 
	int child = heap[0]; 
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

void insertNumbers(int **arr, int from, int to) {
	if (arr[from] == NULL) return; 
	arr[from][++arr[from][0]] = to; 
	heap_sort(arr[from]); 
}

void removeNumber(int *heap) {
	// arr 에 있는 숫자는 없애 줘야 함.
	if (heap == NULL || heap[0] == 0) return; 
	heap[1] = heap[heap[0]]; 
	heap[0]--; 

	// bubble down. 
	int parent = 1; 
	int child = parent * 2;
	int temp;  

	while (child <= heap[0]) {
		if (child + 1 <= heap[0] && heap[child] > heap[child + 1]) {
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

void insertQueue(int *queue, int number) {
	queue[++size] = number; 
}

void deleteQueue(int *queue) {

	for (int i = 2; i <= size; i++) {
		queue[i-1] = queue[i]; 
	}
	size--; 
}

void bfsSearch(int **arr, int *visited, int *queue, int start) {

	int i; 
	int index; 

	while (size != 0) {

		i = queue[1];
		// printf("i: %d\n", i);  

		// printf("-----\n"); 
		// for (int j = 1; j <= size; j++) {
		// 	printf("queue[%d]: %d\n",j, queue[j]); 
		// }

		if (arr[i] == NULL || arr[i][0] == 0) {
			deleteQueue(queue); 
			continue; 
		}

		index = arr[i][0]; 
		for (int j = 1; j <= index; j++) {
			if (visited[arr[i][1]] == 0) {
				visited[arr[i][1]] = count++; 
				insertQueue(queue, arr[i][1]); 
			} 
			removeNumber(arr[i]); 
		}
		deleteQueue(queue); 

	}

}

int main()
{
	// 숫자 입력 받기. 
	int N, M, R; 
	scanf("%d %d %d", &N, &M, &R); 

	// 메모리 동적 할당. 
	// int **arr = (int **)calloc(N+1, sizeof(int *));
	int *sizeArr = (int *)calloc(N+1, sizeof(int)); 
	fromTo *nodes = (fromTo *)malloc(sizeof(fromTo) * (M+1));
	// 하루종일 런타임 에러가 났었는데...
	// 그 이유가 nodes 를 M+1 만큼이 아닌 N+1 개의 메모리만 할당해 주었기 때문이다. 
	int from, to; 
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to); 
		nodes[i].from = from; 
		nodes[i].to = to; 
		sizeArr[from]++; 
		sizeArr[to]++; 
	}

	int **arr = (int **)calloc(N+1, sizeof(int *));
	for (int i = 1; i <= N; i++) {
		if (sizeArr[i] == 0) arr[i] = NULL; 
		else arr[i] = (int *)calloc(sizeArr[i] + 1, sizeof(int)); 
	}
	free(sizeArr); 

	// 숫자들을 공간에 오름차순으로 정렬하여 삽입. 
	for (int i = 1; i <= M; i++) {
		from = nodes[i].from; 
		to = nodes[i].to; 
		insertNumbers(arr, from, to);
		insertNumbers(arr, to, from); 
	}
	free(nodes); 

	// // 본격 BFS 시작.
	int *visited = (int *)calloc(N+1, sizeof(int));

	// 큐 생성. 
	int *queue = (int *)malloc(sizeof(int) * (N+1)); 
	// 처음의 큐와 visited 의 상태. 
	insertQueue(queue, R); 
	visited[R] = count++; 
	bfsSearch(arr, visited, queue, R); 

	// 출력. 
	for (int i = 1; i <= N; i++) {
		printf("%d\n", visited[i]);
	}

	// 메모리 해제. 
	for (int i = 1; i <= N; i++) {
		if (arr[i] != NULL) {
			free(arr[i]); 
		}
	}
	free(arr); free(visited); 
}