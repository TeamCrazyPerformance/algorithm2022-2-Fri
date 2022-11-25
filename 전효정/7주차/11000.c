#include <stdio.h>
#include <stdlib.h>

int max = 1; 

// 이 프로그램은 시간 초과 발생...

typedef struct _Node {
	int start; 
	int end; 
} Node; 

int assignClassroom(Node *heap, Node *classroom, int size) {

	int count = 1; 
	while (classroom[count].end > heap[1].start) {
		count++;  
		if (count > max) max = count; 
	}
	classroom[count] = heap[1];

	// bubble down.
	heap[1] = heap[size--]; 
	int parent = 1; 
	int child = parent * 2; 

	while (child <= size) {

		if (child + 1 <= size && 
			heap[child].start > heap[child+1].start) {
			child++; 
		}

		if (heap[parent].start > heap[child].start) {
			Node temp = heap[parent]; 
			heap[parent] = heap[child]; 
			heap[child] = temp; 

			// 이 부분을 왜 안 넣고 있었을까...?
			parent = child; 
			child *= 2; 
		} else {
			break; 
		}
	}
	return max; 
}

void heap_sort(Node *heap, int i) {
	// bubble up.
	int child = i; 
	int parent = child / 2;

	while (child != 1) {
		if (heap[parent].start > heap[child].start) {
			Node temp = heap[parent]; 
			heap[parent] = heap[child]; 
			heap[child] = temp; 

			// 이걸 왜 안 넣었을까...?
			child = parent; 
			parent /= 2; 
		} else {
			break; 
		}
	}
}

int main()
{
	int N; 
	scanf("%d", &N); 
	Node *heap = (Node *)malloc(sizeof(Node) * (N+1));
	Node *classroom = (Node *)malloc(sizeof(Node) * (N+1));  

	classroom[1].start = -1; 
	classroom[1].end = -1; 

	int start, end; 
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &start, &end);
		heap[i].start = start; 
		heap[i].end = end;
		heap_sort(heap, i);  
	}

	int size = N; 
	int result; 
	for (int i = 1; i <= N; i++) {
		result = assignClassroom(heap, classroom, size);
		size--; 
	}
	printf("%d\n", result);

	free(heap); free(classroom); 
}