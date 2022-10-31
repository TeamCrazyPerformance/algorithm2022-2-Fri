#include <stdio.h>
#include <stdlib.h>

// 머지 소트 타임아웃. 
// void merge(int sangeun[], int sorted[], int start, int mid, int end){
// 	int i, j, k; 
// 	i = start; 
// 	j = mid + 1; 
// 	k = start; 

// 	while (i <= mid && j <= end) {
// 		if (sangeun[i] <= sangeun[j]) {
// 			sorted[k++] = sangeun[i++];
// 		} else {
// 			sorted[k++] = sangeun[j++];
// 		}
// 	}

// 	while (i <= mid) {
// 		sorted[k++] = sangeun[i++]; 
// 	}

// 	while (j <= end) {
// 		sorted[k++] = sangeun[j++]; 
// 	}

// 	for (i = start; i <= end; i++) {
// 		sangeun[i] = sorted[i];
// 	}

// }

// void merge_sort(int sangeun[], int sorted[], int left, int right) {
// 	int mid; 

// 	if (left < right) {
// 		mid = (left + right)/2;
// 		merge_sort(sangeun, sorted, 0, mid - 1);
// 		merge_sort(sangeun, sorted, mid + 1, right); 
// 		merge(sangeun, sorted, left, mid, right); 
// 	}

// }

void insertNode(int sangeun[], int num, int index) { 
	sangeun[index] = num; 

	while (index != 1) {
		if (sangeun[index/2] > num) {
			sangeun[index] = sangeun[index/2];
		} else {
			break;
		}
		index /= 2; 
	}
	sangeun[index] = num; 
}

void deleteNode(int sangeun[], int size) {
	sangeun[1] = sangeun[size--]; 
	int num = sangeun[1]; 
	int parent = 1; 
	int child = parent * 2; 

	while (child <= size) {

		if (child + 1 <= size && sangeun[child] > sangeun[child + 1]) {
			child++; 
		}

		if (num > sangeun[child]) {
			sangeun[parent] = sangeun[child]; 
			parent = child; 
			child *= 2; 
		} else {
			break; 
		}
	}

	sangeun[parent] = num; 

}

void heap_sort(int sangeun[], int sorted[], int N) {
	int k = 0, size = N; 

	while (k < N) {
		sorted[k++] = sangeun[1]; 
		deleteNode(sangeun, size); 
		size--; 
	}
}

int binary_search(int cards[], int N, int num) {
	int left, right, midpoint;
	left = 0; right = N; 

	while (left <= right) {
		midpoint = (left + right) / 2;

		if (cards[midpoint] == num) return 1;

		if (cards[midpoint] < num) {
			left = midpoint + 1; 
		} else if (cards[midpoint] > num) {
			right = midpoint - 1; 
		}
	}

	return 0; 
}

int main()
{
	int N, M, num, result;
	scanf("%d", &N); 

	int *sangeun = (int *)malloc(sizeof(int *) * (N+1)); 
	int *sorted = (int *)malloc(sizeof(int *) * N); 

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num); 
		// 상근이의 카드 최소 힙으로 구성하기. 
		insertNode(sangeun, num, i);
	} 

	
	//int *cards = (int *)malloc(sizeof(int *) * M); 
	// 상근이의 카드 머지 소팅하기. 
	//merge_sort(sangeun, sorted, 0, N - 1); 
	// for (int i = 1; i <= N; i++) {
	// 	printf("sang: %d\n", sangeun[i]); 
	// }

	// 상근이의 카드 힙 소팅하기. 
	heap_sort(sangeun, sorted, N);
	
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &num); 
		result = binary_search(sorted, N - 1, num);
		printf("%d ", result);
	}
	

	free(sangeun); 
	free(sorted);
	//free(cards);
}