#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAXSIZE 500001
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
using namespace std;

int sorted[MAXSIZE];
void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; //합병할 리스트 첫번째의 첫번째 인덱스
	j = mid + 1; //합병할 리스트 두번째의 첫번째 인덱스
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) for (l = j; l <= right; l++)sorted[k++] = list[l];
	else for (l = i; l <= mid; l++) sorted[k++] = list[l];
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}
void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
int Binary_Search(int list[], int target, int start, int end){
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (list[mid] < target) start = mid + 1;
		else if (list[mid] > target) end = mid - 1;
		else if (list[mid] == target) return 1;
	}
	return 0;
}

int main() {
	int N, M;
	cin >> N;
	int* N_list = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &N_list[i]);
	}
	cin >> M;
	int* M_list = new int[M];
	for (int i = 0; i < M; i++) {
		scanf("%d", &M_list[i]);
	}
	merge_sort(N_list, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		printf("%d ", Binary_Search(N_list, M_list[i], 0, N - 1));
	}
}
