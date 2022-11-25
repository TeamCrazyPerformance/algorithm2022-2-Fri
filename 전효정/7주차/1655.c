#include <stdio.h>
#include <stdlib.h>

void insertHeap(int heap[], int number, int size) {
	heap[size] = number; 
	int val = heap[size]; 
	int child = size; 
	int parent = child / 2; 

	while (child != 1) {
		if (heap[parent] > val) {
			heap[child] = heap[parent]; 
			child = parent; 
			parent /= 2; 
		} else {
			break; 
		}
	}

	heap[child] = val; 
}

void deleteHeap(int heap[], int size) { 
	heap[1] = heap[size--]; 
	int val = heap[1];
	int parent = 1; 
	int child = parent * 2; 

	while (child <= size) {
		if (child + 1 <= size && heap[child] > heap[child + 1]) {
			child++; 
		}
		if (heap[child] < val) {
			heap[parent] = heap[child]; 
			parent = child; 
			child *= 2; 
		} else {
			break; 
		}
	}

	heap[parent] = val; 
}

void heap_sort(int heap[], int sorted[], int n) {
	int num; 
	for (int i = 1; i <= n; i++) {
		num = heap[i]; 
		insertHeap(heap, num, i); 
	}

	int size = n; 
	for (int i = 1; i <= n; i++) {
		sorted[i] = heap[1]; 
		deleteHeap(heap, size); 
		size--; 
	}

	for (int i = 1; i <= n; i++) {
		heap[i] = sorted[i]; 
	}

}

int main()
{
	int N, num; 
	scanf("%d", &N); 
	int *heap = (int *)malloc(sizeof(int) * (N+1));
	int *sorted = (int *)malloc(sizeof(int) * (N+1)); 
	int *result = (int *)malloc(sizeof(int) * (N+1));  

	int index;  
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num); 
		heap[i] = num; 
		heap_sort(heap, sorted, i);
		// if (i % 2 == 0) {
		// 	indicator++; 
		// } 
		if (i%2) {
			index = i / 2 + 1;
		} else {
			index = i / 2; 
		}

		result[i] = sorted[index];
	
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i] );
	}

	free(heap); free(sorted); free(result); 
}