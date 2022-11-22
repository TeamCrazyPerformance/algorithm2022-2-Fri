#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>
// 이 풀이는 [메모리 초과] 발생.
// 메모리 제한: 12 MB 
// Node 구조체의 크기는 16 byte.
// N * N * 16 = 36,000,000 (36 MB)

typedef struct _Node {
	struct _Node *next; 
	int number; 
} Node; 

void addTheNode(Node *arr, int j, int num) {

	// arr[j] 에다가 num 을 담은 노드를 연결할 것임.
	Node *newNode = (Node *)malloc(sizeof(Node)); 
	newNode -> number = num; 
	newNode -> next = NULL;

	if (arr[j].next == NULL) { 
		// 만약 배열 공간의 다음 노드가 NULL 이라면. 
		arr[j].next = newNode; 
	} else {
		// 만약 배열 공간의 다음 노드에 다른 노드가 이미 연결되어 있다면. 
		newNode -> next = arr[j].next; 
		arr[j].next = newNode; 
	}

}

void bubbleUp(Node *arr, int j, int num) {

	arr[j].number = num; 
	int child = j; 
	int parent = child / 2; 
	Node temp;


	while (child != 1) {

		if (arr[parent].number < arr[child].number) {
			temp = arr[child]; 
			arr[child] = arr[parent]; 
			arr[parent] = temp; 

			child = parent; 
			parent /= 2; 
		} else {
			break;
		}
	}

}

void bubbleDown(Node *arr, int N) {
 
	int parent = 1; 
	int child = parent * 2; 
	Node temp; 

	while (child <= N) {
		if (child + 1 <= N && arr[child].number < arr[child+1].number) {
			child++; 
		}

		if (arr[child].number > arr[parent].number) {
			temp = arr[child]; 
			arr[child] = arr[parent];
			arr[parent] = temp; 

			parent = child; 
			child *= 2; 
		} else {
			break;
		}
	}

}

void deleteAndUpdate(Node *arr, int N) {
	// arr[1] 노드를 빼고, arr[1]에 연결된 다음 노드를 arr[1] 자리에 갱신. 
	// -> bubbleDown 과정이 진행됨. 

	// if (arr[1].next == NULL) { // arr[1]에 연결된 노드가 없다면. ==> 그럴 리가 없겠구나.
	// 	// 연결 된 노드의 수는 N개니까. 
	// 	arr[1].number = INT_MIN; 
	// } else { // arr[1] 에 연결된 노드가 있다면. 
	arr[1] = *arr[1].next; 
	//}


	bubbleDown(arr, N); 
}

void deleteNode(Node *head) { // head 노드의 다음 노드를 삭제. 
	if (head -> next == NULL) {
		//printf("NULL!\n"); 
		return; 
	}
	
	Node *target = head -> next; 
	//printf("target: %d\n", target -> number); 
	if (target -> next != NULL) {
		head -> next = target -> next; 
		free(target);
	} else {
		free(target); 
		head -> next = NULL; 
	}
 
}

int main()
{
	int N; 
	scanf("%d", &N); 
	// 구조체 Node 타입의 1차원 배열.
	Node *arr = (Node *)malloc(sizeof(Node) * (N+1)); 

	printf("\nsizeof: %d\n", sizeof(Node)); 
	// 구조체 배열 초기화. 
	for (int head = 1; head <= N; head++) {
		arr[head].next = NULL; 
	}

	// 배열 공간에 있는 숫자들의 최댓값을 arr[0]에
	// 넣는 과정이다.
	// N^N 배열에서 마지막 줄에 있는 노드들은 배열 공간에,
	// 그렇지 않는 노드들은 배열 노드에서 연결 리스트로 연결시킨다.  
	int num; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num); 
			if (i == N) {
				//arr[j] -> number = num; 
				bubbleUp(arr, j ,num); 
			}
			else addTheNode(arr, j ,num); 
		}
	}

	// 배열 공간에는 연결된 노드들의 최댓값이 들어 있다. 
	// 최댓값을 빼내고 다음으로 큰 수를 담은 노드를 arr[1]에
	// 넣는 과정.

	for (int i = 1; i < N; i++) {
		deleteAndUpdate(arr, N); 
		// for (int head = 1; head <= N; head++) {
		// 	Node *curr = &arr[head]; 
		// 	while (curr != NULL) {
		// 		printf("%d ", curr -> number); 
		// 		curr = curr -> next; 
		// 	}
		// 	printf("\n"); 
		// }
		// printf("=====\n"); 
	} 

	printf("%d\n", arr[1].number);
		
	for (int head = 1; head <= N; head++) {
		while (arr[head].next != NULL) {
			deleteNode(&arr[head]); 
		}
	}
	free(arr); 
}