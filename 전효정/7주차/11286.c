#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int positive; 
	int number;
} Node; 

void swap(Node *heap, int parent, int child) {
	Node temp = heap[child]; 
	heap[child] = heap[parent]; 
	heap[parent] = temp;  
}

int deleteReturn(Node *heap, int size) {

	int result = heap[1].number * heap[1].positive; 
	heap[1] = heap[size--]; 
	int parent = 1; 
	int child = parent * 2; 

	// bubble down
	while (child <= size) {
		if (child + 1 <= size) {
			if(heap[child].number > heap[child + 1].number) child++; 


			// 이 부분을 추가하지 않아서 틀렸습니다 가 떴음. (백준 게시판에서 깨달음을 얻음.)
			else if (heap[child].number == heap[child+1].number) {
				if (heap[child].positive > heap[child+1].positive) {
					child++; 
				}
			}
		}

		if (heap[parent].number >= heap[child].number) {
			if (heap[parent].number == heap[child].number &&
				heap[parent].positive < heap[child].positive) break; 
			swap(heap, parent, child); 
			parent = child; 
			child *= 2; 
		} else {
			break; 
		}
	}

	return result; 
}

void insertNode(Node *heap, int i) {
	int child = i; 
	int parent = child / 2; 

 	// bubble up
	while (child != 1) {
		if (heap[parent].number >= heap[child].number) {
			if (heap[parent].number == heap[child].number &&
				heap[parent].positive < heap[child].positive) break;
			swap(heap, parent, child); 
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
	int *min = (int *)malloc(sizeof(int) * N); 

	int num;
	int result;
	int size = 0;
	int k = 0;    
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num); 
		if (num == 0) {
			if (size == 0) min[k++] = 0; 
			else {
				min[k++] = deleteReturn(heap, size); 
				size--;
			}    
		} else {
			size++; 

			if (num < 0) heap[size].positive = -1; 
			else heap[size].positive = 1; 

			heap[size].number = num * heap[size].positive; 
			insertNode(heap, size);
		}
		// printf("===\n"); 
		// for (int index = 1; index <= size; index++) {
		// 	printf("%d\n", heap[index].number * heap[index].positive); 
		// }
		// printf("===\n");
	}

	for (int i = 0; i < k; i++) {
		printf("%d\n", min[i]); 
	}
	free(heap); free(min); 
}