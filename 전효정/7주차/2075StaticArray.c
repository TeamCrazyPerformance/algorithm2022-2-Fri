#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int order; 
	int number; 
} Node;

void insertNode(Node *heap, int i) {
	int child = i; 
	int parent = child/2;

	// bubble up.
	while (child != 1) {
		if (heap[parent].number < heap[child].number) {
			Node temp = heap[child]; 
			heap[child] = heap[parent]; 
			heap[parent] = temp;

			child = parent; 
			parent /= 2; 
		} else {
			break; 
		}
	}
}

void NthLargest(int **arr, Node *heap, int *count, int N) {
	int index = heap[1].order;
	//printf("count[%d]: %d\n", index, count[index]); 
	heap[1].number = arr[count[index]--][index]; 
	
	//printf("heap[1].number: %d\n", heap[1].number); 
	// bubble down.
	int parent = 1; 
	int child = parent * 2; 

	while (child <= N) {
		if (child + 1 <= N && heap[child].number < heap[child + 1].number) {
			child++; 
		}

		if (heap[child].number > heap[parent].number) {
			Node temp = heap[child]; 
			heap[child] = heap[parent]; 
			heap[parent] = temp;

			parent = child; 
			child *= 2; 
		} else {
			break; 
		}
	}
}
 
int main()
{
	int N; 
	scanf("%d", &N); 

	// 메모리 할당
	int **arr = (int **)malloc(sizeof(int *) * N);
	int *count = (int *)malloc(sizeof(int) * (N+1));
	for (int i = 1; i < N; i++) {
		arr[i] = malloc(sizeof(int) * (N+1)); 
		count[i] = N-1; 
	}  
	count[N] = N-1; 
	// 힙 생성. 
	Node *heap = (Node *)malloc(sizeof(Node) * (N+1)); 

	// 숫자 입력 받기. 
	int num; 
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num); 
			arr[i][j] = num; 
		}
	}

	// 구조체 입력 받기. 
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num); 
		heap[i].order = i; 
		heap[i].number = num;
		insertNode(heap, i); 
	}

	for (int i = 1; i < N; i++) {
		NthLargest(arr, heap, count, N); 
		// for (int j = 1; j <= N; j++) {
		// 	printf("heap[%d]: %d\n", j, heap[j].number); 
		// }
		// printf("\n"); 
	}

	printf("%d\n", heap[1].number);

	// 메모리 해제	
	for (int i = 1; i < N; i++) {
		free(arr[i]); 
	}
	free(arr); free(count); 

	free(heap); 

}