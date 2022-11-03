#include <stdio.h>
#include <stdlib.h>

// ------ 힙 정렬 -------
void insertNode(int trees[], int i, int tree) {
	int child = i;  
	int parent = child / 2; 

	while (child != 1) {
		if (trees[parent] < tree) {
			trees[child] = trees[parent]; 
			child = parent; 
			parent /= 2; 
		} else {
			break; 
		}
	}

	trees[child] = tree; 
}

void deleteNode(int trees[], int size) {
	trees[1] = trees[size--]; 
	int val = trees[1]; 

	int parent = 1; 
	int child = parent * 2; 

	while (child <= size) {

		if (child + 1 <= size && trees[child] < trees[child + 1]) {
			child++; 
		}

		if (trees[child] > val) {
			trees[parent] = trees[child]; 
			parent = child; 
			child *= 2; 
		} else {
			break;	
		}
	}
	trees[parent] = val;

}

void heap_sort(int trees[], int sorted[], int N) {
	int k = 0;
	int size = N;

	while (k < N) {
		sorted[k++] = trees[1]; 
		deleteNode(trees, size); 
		size--; 
	}
}
// ----- 힙 정렬 끝 -----

// ====== 나무 자르기 =======
int cutTrees(int trees[], int max, int N, int M) {
	long long min = 0, sum = 0, mid; 

	// 백준 질문에서. 오버 플로우 문제??????
	// M의 최댓값: 2,000,000,000
	// int의 최댓값: 2,147,483,647
				 	// 결괏값의 최대:2,000,000,000,000,000
	// unsigned int의 최댓값: 		  4,294,967,295
	// long의 최댓값: 	        	  2,147,483,647
	// signed long long의 최댓값:   9,223,372,036,854,775,807
	// unsigned long long의 최댓값: 18,446,744,073,709,551,615
	// 아... 이것이 문제로구나.


	while ( sum != M ) {
		sum = 0; 
		mid = (max + min) / 2;
		if (mid == min) {
			break; 
		}

		for (int i = 0 ; i < N; i++) {
			if (trees[i] <= mid) break; 
			sum += (trees[i] - mid);
			if (sum > M) break; 
		}	

		if (sum > M) min = mid; 
		else if (sum < M) max = mid; 
	}

	return mid; 
}
// ======================

int main()
{
	int N, M, tree, max = 0;
	scanf("%d %d", &N, &M); 

	int *trees = (int *)malloc(sizeof(int) * (N+1)); 
	int *sorted = (int *)malloc(sizeof(int) * N); 

	for (int i = 1; i <= N; i++) {
		scanf("%d", &tree);
		insertNode(trees, i, tree); 
		if (tree > max) {
			max = tree; 
		}
	}

	//내림차순으로 정렬. 
	heap_sort(trees, sorted, N);

	int result = cutTrees(sorted, max, N, M); 
	printf("%d\n", result);

	free(trees); free(sorted); 
}