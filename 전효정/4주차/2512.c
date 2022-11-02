#include <stdio.h>
#include <stdlib.h>

// ------------- 힙 정렬 시작 ----------------
void insertNode(int budget[], int num, int child) {
	int parent = child / 2;

	while (child != 1) {
		if (budget[parent] > num) {
			budget[child] = budget[parent];
			child = parent;
			parent /= 2; 
		} else {
			break; 
		}
	}

	budget[child] = num; 
}

void deleteNode(int budget[], int size) {
	budget[1] = budget[size--];
	int val = budget[1];  
	
	int parent = 1; 
	int child = parent * 2; 

	while (child <= size) {
		if (child + 1 <= size && budget[child] > budget[child+1]) {
			child++; 
		}
		if (budget[child] < val) {
			budget[parent] = budget[child];
			parent = child; 
			child *= 2;  
		} else {
			break; 
		}
	}
	budget[parent] = val; 
}

void heap_sort(int budget[], int sorted[], int size) {
	int k = 0, N = size; 

	while (k < N) {
		sorted[k++] = budget[1]; 
		deleteNode(budget, size); 
		size--; 
	} 
}
// ------------- 힙 정렬 끝 ----------------



// =====================================================
// !!!!!!!!!!!!!!!!!!!이 문제의 하이라이트!!!!!!!!!!!!!!!!!!!
// *****************************************************
int binary_search(int budget[], int right, int ave, int M) {
	int left = 0; 
	int mid = 0; 
	int size = right; 

	while (right - left >= 1) {
		mid = (left + right) / 2;
		//printf("mid: %d\n", mid); 

		if (budget[mid] == ave) {
			mid++;
			break;
		}
		if (budget[mid] < ave) {
			left = mid + 1; 
		} else if (budget[mid] > ave) {
			right = mid - 1; 
		}
	}
	//mid는 평균보다 작고 큰 원소들을 구분하는 구분점이 된다. 

	int sum = 0;
	int sumOfVal = 0; 
	//printf("mid: %d\n", mid);  
	for (int i = 0; i < mid; i++) {
		sum += (ave - budget[i]);
		sumOfVal += budget[i]; 
	}
	//printf("mid: %d\n", mid); 
	int index = mid;  

	//printf("mid: %d print size: %d\n", mid, size); 
	sum /= (size - mid + 1);
	//printf("ave: %d sum: %d size: %d index: %d\n", ave, sum, size, mid); 
	int limit = ave + sum; 

	//printf("limit: %d\n", limit); 
	// # 1. 
	// 평균보다 크고, 상한선보다 작은 원소가 있는지 확인. 
	// 상한선과 값이 같은 원소가 있다면??????
	while (mid <= size && budget[mid] <= limit) {
		limit += ((limit - budget[mid])/(size - mid));
		sumOfVal += budget[mid]; 
		mid++; 
	}

	// # 2. 
	// (그동안 원소들의 합) + (상한액 * 남은 원소들의 갯수) <= 총 예산 
	// // 일 때 반복. 
	int count = size - mid + 1; 
	while (mid <= size) {
		//printf("count: %d limit + 1 * count + sumOfVal: %d\n",  count, (limit + 1) * count + sumOfVal );
		if ( (limit + 1) * count + sumOfVal > M) break;
		
		limit++;

		if (budget[mid] <= limit) {
			sumOfVal += budget[mid]; 
			count--;
			mid++; 
		}
	
	}
	return limit; 
}

// =====================================================
// !!!!!!!!!!!!!!!!!!!이 문제의 하이라이트!!!!!!!!!!!!!!!!!!!
// *****************************************************




int main()
{
	int N, M, num, ave = 0;
	scanf("%d", &N); 

	int *budget = (int *)malloc(sizeof(int) * (N+1)); 
	int *sorted = (int *)malloc(sizeof(int) * N); 

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num); 
		ave += num; 
		insertNode(budget, num, i);  
	}
 
	scanf("%d", &M);


	//머지 소트 시간초과!!!!!!
	//merge_sort(budget, sorted, 0, N-1);
	//힙 소트 써야 하나??
	heap_sort(budget, sorted, N); 

	// for (int i = 0; i < N; i++) {
	// 	printf("%d\n", sorted[i]); 
	// }

	// 만약에 모든 예산의 합이 총 예산을 넘지 않는다면, 최댓값을 출력. 
	if (ave <= M) {
		printf("%d", sorted[N-1]);
		free(budget); free(sorted); 
		return 0;  
	}

	// 그게 아니라면?
	// 일단 예산의 평균을 구한다. 총 예산 / 원소의 개수 

	ave = M/N;
	
	// ave 를 넘는 원소들은 차이만큼 빼어 어느 변수에 합하고
	// ave 를 넘지 않는 원소들은 넘어 간다. 
	// budget 이 오름차순으로 정렬되어 있기 때문에, 이분 탐색으로
	// 이 구분점 index 를 찾는다. 

	// =======> 평균보다 크고, 상한선보다 작은 원소들이 없어질 때까지 
	// 위 과정을 반복해야 한다.
	int result = binary_search(sorted, N-1, ave, M); 

	//sum /= index; 
	//sum을 index로 나누는 게 아니라,
	// N - index 로 나누어야 하지 않을까? 
	//sum /= (N-index); 

	// 상한액: ave + sum
	printf("%d\n", result); 

	free(budget); free(sorted); 
	return 0; 
}