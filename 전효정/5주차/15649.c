// 2022.11.9.(수)
// 백트래킹 구현이 잘 이해되지 않아서
// 코드를 그냥 통째로 외웠다. 

#include <stdio.h>

int visited[9] = {0}; 

void recur(int arr[], int index, int N, int M) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n"); 
		return; 
	} else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				arr[index] = i; 
				visited[i] = 1; 
				recur(arr, index + 1, N, M); 
				visited[i] = 0; 
			}
		}
	}

}

int main()
{
	int N, M;
	int arr[9] = {0};  
	scanf("%d %d", &N, &M); 

	recur(arr, 0, N, M); 

	return 0; 
}