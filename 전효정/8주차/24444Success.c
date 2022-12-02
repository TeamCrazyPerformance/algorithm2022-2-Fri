#include <stdio.h>
#include <stdlib.h>

// 이 프로그램은 메모리 초과...
// 큐를 배열로 만들어야 할까? 

// 계속 Segfault 오류..
// 도대체 뭘까? 
int count = 1; 

typedef struct _Queue {
	struct _Queue *next; 
	struct _Queue *prev; 
	int number; 
} Queue; 

typedef struct _fromTo {
	int from; 
	int to; 
} fromTo;

void heap_sort(int *heap) {
	int child = heap[0]; 
	int parent = child / 2; 
	int temp; 

	// bubble up. 
	//printf("========child: %d\n", child); 
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
		//printf("parent: %d, child: %d\n", parent, child); 
	}


	// printf("-----\n"); 
	// printf("size: %d\n", heap[0]); 
	// for (int i = 1; i <= heap[0]; i++) {
	// 	printf("heap: %d\n", heap[i]); 
	// }
	// printf("-----\n"); 
}

void insertNumbers(int **arr, int from, int to) {
	int size = ++arr[from][0]; 
	arr[from][size] = to;
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

void insertQueue(Queue *end, int number) {
	Queue *newNode = (Queue *)malloc(sizeof(Queue)); 
	newNode -> number = number; 

	end -> prev -> next = newNode;
	newNode -> prev = end -> prev;  
	end -> prev = newNode;
	newNode -> next = end; 
}

void deleteQueue(Queue *front, Queue *end) {
	Queue *target = front -> next; 

	if (front -> next == end) return; 

	front -> next = target -> next; 
	target -> next -> prev = front; 
	free(target); 
}

void bfsSearch(int **arr, int *visited, Queue *front, Queue *end) {

	int i, size; 

	while (front -> next != end) {
		i = front -> next -> number; 

		if (arr[i] == NULL || arr[i][0] == 0) {
			deleteQueue(front, end);
			continue; 
		}

		size = arr[i][0]; 
 
		for (int j = 1; j <= size; j++) {
			if (visited[arr[i][1]] == 0) {
				visited[arr[i][1]] = count++;
				insertQueue(end, arr[i][1]);  
			}
			removeNumber(arr[i]);
		}

		// Queue *curr = front -> next; 
		// printf("-----\n");
		// while (curr != end) {
		// 	printf("curr: %d\n", curr -> number); 
		// 	curr = curr -> next; 
		// }
		// deleteQueue(front, end); 
	}
}

int main()
{
	// 숫자 입력 받기. 
	int N, M, R; 
	scanf("%d %d %d", &N, &M, &R); 

	// 메모리 동적 할당. 
	int *sizeArr = (int *)calloc(N+1, sizeof(int)); 
	fromTo *nodes = (fromTo *)malloc(sizeof(fromTo) * (M+1));

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
		if (sizeArr[i] != 0) 
			arr[i] = (int *)calloc(sizeArr[i] + 1, sizeof(int)); 
		else
			arr[i] = NULL; 
	}
	free(sizeArr); 

	// printf("sizeofQueue: %d\n", sizeof(Queue));
	// printf("sizeoffromTo: %d\n", sizeof(fromTo));
	// 숫자들을 공간에 오름차순으로 정렬하여 삽입. 
	for (int i = 1; i <= M; i++) {
		from = nodes[i].from; 
		to = nodes[i].to; 
		insertNumbers(arr, from, to);
		insertNumbers(arr, to, from); 
	}
	free(nodes); 

	// 본격 BFS 시작.
	int *visited = (int *)calloc(N+1, sizeof(int));

	// 큐 생성. 
	Queue *front = (Queue *)malloc(sizeof(Queue)); 
	Queue *end = (Queue *)malloc(sizeof(Queue)); 
	front -> next = end; 
	front -> prev = NULL; 
	end -> next = NULL; 
	end -> prev = front; 

	// 처음의 큐와 visited 의 상태. 
	insertQueue(end, R); 
	visited[R] = count++; 

	bfsSearch(arr, visited, front, end); 


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
	free(front); free(end); 
}