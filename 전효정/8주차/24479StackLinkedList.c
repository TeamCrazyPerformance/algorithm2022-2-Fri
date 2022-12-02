#include <stdio.h>
#include <stdlib.h>

// 스택: 연결 리스트
// 그래프: 이차원 배열.
// 이건 또 메모리 초과.....
// linked list 를 없애야 하나? 

int arr[100001][100001] = {0}; 

int count = 1; 

typedef struct _stack {
	struct _stack *next; 
	int number; 
} Stack;

void insertStack(Stack *head, Stack *tail,
	int number) {
	Stack *newNode = malloc(sizeof(Stack)); 
	newNode -> number = number; 

	newNode -> next = head -> next; 
	head -> next = newNode; 
}

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

void insertNumber(/*int **arr,*/ int from, int to) {
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

void dfsSearch(/*int **arr,*/ int start, int *visitedOrder, Stack *head, Stack *tail) {

	int i; 

	while (head -> next != tail) {
		i = head -> next -> number; 

		if (!arr[i][0]) {
			// 아무 원소가 없다면. 스택에서 숫자 제거. 
			Stack *target = head -> next;
			head -> next = target -> next; 

			free(target); 

		} else {
			
			if (!visitedOrder[arr[i][1]]) {
				// 방문을 안했었더라면. 
				visitedOrder[arr[i][1]] = count++; 
				insertStack(head, tail, arr[i][1]); 
			}

			deleteFirstNode(arr[i]); 

		}

		// printf("-------\n"); 
		// Stack *curr = head -> next;
		// while (curr != tail) {
		// 	printf("stack: %d\n", curr -> number);
		// 	//printf("arr[i][0]: %d\n", arr[i][0]); 
		// 	curr = curr -> next; 
		// }
		// printf("------\n"); 
		// for (int i = 0; i <= 5; i++) {
		// 	for (int j = 0; j <= 5; j++) {
		// 		printf("%d ", arr[i][j]);
		// 	}
		// 	printf("\n"); 
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
	int *visitedOrder = (int *)calloc(N+1, sizeof(int)); 

	visitedOrder[R] = count++; 
	// DFS 탐색 본격 시작. 
	int from, to; 
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to); 
		insertNumber(/*arr,*/ from, to);
	}


	Stack *head = (Stack *)malloc(sizeof(Stack)); 
	Stack *tail = (Stack *)malloc(sizeof(Stack)); 

	Stack *firstNode = (Stack *)malloc(sizeof(Stack)); 
	firstNode -> number = R; 
	firstNode -> next = tail; 
	head -> next = firstNode; 
	tail -> next = NULL; 

	//printf("size: %d\n", sizeof(Stack)); 


	// dfs 탐색. 
	dfsSearch(/*arr,*/ R, visitedOrder, head, tail); 

	for (int i = 1; i <= N; i++) {
		printf("%d\n", visitedOrder[i]); 
	}


	//메모리 해제. 
	// for (int i = 0; i <= N; i++) {
	// 	free(arr[i]); 
	// }

	while (head -> next != tail) {
		Stack *target = head -> next; 
		head -> next = target -> next; 

		free(target);  
	}
	free(head); free(tail); 
	// free(arr); 
	free(visitedOrder); 
}