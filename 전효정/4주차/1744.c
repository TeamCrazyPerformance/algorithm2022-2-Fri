#include <stdio.h>
#include <stdlib.h>

// -------- 선택 정렬 ---------
void insertion_sort(int arr[], char pOrN, int N) {
	// positive는 내림차순으로,
	// negative는 오름차순으로 정렬한다.
	
	int temp; 
	// 내림차순
	if (pOrN == 'p') {
		for (int i = 0; i < N; i++) {
			temp = arr[i]; 
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] < temp) {
					arr[j+1] = arr[j]; 
					arr[j] = temp; 
				} else {
					break; 
				}
			}
		}
	}
	// 오름차순
	else if (pOrN == 'n') {
		for (int i = 0 ; i < N; i++) {
			temp = arr[i]; 
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] > temp) {
					arr[j+1] = arr[j];
					arr[j] = temp;  
				} else {
					break; 
				}
			}
		}
	}
}
// --------------------------

// ========= 수 묶어 최댓값 계산하기 =========
int bundleUp(int arr[], int k) {
	int i = 0, max = 0; 

	while (i + 1 < k) {
		max += arr[i] * arr[i+1]; 
		i += 2; 
	}
	if (i == k - 1) max += arr[i]; 

	return max; 
}

int main() 
{
	int N, num, sizePos = 0, sizeNeg = 0, sum = 0;
	int positive[51], negative[51];
	scanf("%d", &N); 

	for (int i = 0; i < N; i++) {
		scanf("%d", &num); 
		if (num == 1) sum += 1; 
		else if (num > 0) positive[sizePos++] = num;
		else if (num <= 0) negative[sizeNeg++] = num;
	}


	// positive는 내림차순으로,
	// negative는 오름차순으로 정렬한다. 
	// 무슨 정렬쓸까? 입력 데이터 수가 최대 50으로 많지 않으니...
	// 버블? 삽입? 선택?
	// ---> 삽입 정렬을 쓰도록 하자. 
	insertion_sort(positive, 'p', sizePos);
	insertion_sort(negative, 'n', sizeNeg);


	// 수 묶어 계산하기. 
	// positive 부터 최대가 나오도록.
	sum += bundleUp(positive, sizePos); 
	// negative bundleUp 구하기. 
	sum += bundleUp(negative, sizeNeg);

	printf("%d\n", sum); 
}