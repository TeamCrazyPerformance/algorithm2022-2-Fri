#include <stdio.h>
#include <stdlib.h>

// 스택: 연결 리스트
// 그래프: 연결 리스트 
// 간선은 '양방향'.
// 93% 시간 초과... 인접 행렬 쓰면 안되나?
int count = 1; 

typedef struct _Node {
	struct _Node *next; 
	int number; 
} Node;

typedef struct _stack {
	struct _stack *next; 
	int number; 
} Stack;

void insertNode(Node *arr, int from, int to) {

	Node *newNode = malloc(sizeof(Node)); 
	newNode -> next = NULL; 
	newNode -> number = to;  
	Node *target = arr[from].next; 

	if (target == NULL) {
		arr[from].next = newNode; 
	} else if (target -> next == NULL) {
		if (to > target -> number) { 
			target -> next = newNode;
		} else {
			newNode -> next = arr[from].next;
			arr[from].next = newNode;  
		}
	} else {
		if (arr[from].next -> number > to) {
			newNode -> next = arr[from].next; 
			arr[from].next = newNode;
		} else {
			// 연결 리스트를 오름차순으로 정렬하기 위함. 
			while (target -> next != NULL && to > 
				target -> next -> number) {
				target = target -> next; 
			}

			newNode -> next = target -> next; 
			target -> next = newNode; 
		}
	}

	Node *newNode2 = malloc(sizeof(Node)); 
	newNode2 -> next = NULL; 
	newNode2 -> number = from; 
	target = arr[to].next; 
	if (target == NULL) {
		arr[to].next = newNode2; 
	} else if (target -> next == NULL) {
		if (from > target -> number) { 
			target -> next = newNode2;
		} else {
			newNode2 -> next = arr[to].next;
			arr[to].next = newNode2;  
		}
	} else {
		// 연결 리스트를 오름차순으로 정렬하기 위함. 
		// 오름차순으로 정렬하는 과정에서 시간초과가 발생하는 것 같은데...

		if (arr[to].next -> number > from) {
			newNode2 -> next = arr[to].next; 
			arr[to].next = newNode2;
		} else {
			while (target -> next != NULL && from > 
				target -> next -> number) {
				target = target -> next; 
			}

			newNode2 -> next = target -> next; 
			target -> next = newNode2; 
		}
	}
}

void insertStack(Stack *head, Stack *tail, int number) {
	Stack *newNode = malloc(sizeof(Stack)); 
	newNode -> number = number; 

	newNode -> next = head -> next; 
	head -> next = newNode; 
}

void deleteNode(Node *arr, int index) {
	Node *target = arr[index].next; 
	if (target == NULL) return; 
	else if (target -> next == NULL) {
		free(target); 
		arr[index].next = NULL; 
	} else {
		arr[index].next = target -> next; 
		free(target); 
	}
}

// dfs (stack 사용)
void dfsSearch(Node *arr, Stack *head, Stack *tail, 
	int *visitOrder) {

	int i, num; 

	while (head -> next != tail) {

		i = head -> next -> number; 

		if (!visitOrder[i]) visitOrder[i] = count++; 

		if (arr[i].next != NULL && visitOrder[arr[i].next -> number]) {
			// 방문한 적이 있다.
			deleteNode(arr, i); 
			continue; 
		} 

		if (arr[i].next == NULL) {
			// 스택에서 빼기.
			Stack *target = head -> next; 
			head -> next = target -> next;
			free(target);  
		} else {
			num = arr[i].next -> number; 
			if (!visitOrder[num]) insertStack(head, tail, num); 
			deleteNode(arr, i);
		}

		// Stack *curr = head -> next; 
		// printf("======\n"); 
		// while (curr != tail) {
		// 	printf("stack: %d\n", curr -> number);
		// 	curr = curr -> next; 
		// }
	}
}

// 메모리 제한이 512 MB 다. 이 정도면
// 이차원 배열을 만들어도 되겠는걸.
// 아니다. 정점의 수가 최대 100,000 개니까.
// 이차원 배열 쓰지 말고 linked list 사용하자. 

int main()
{
	int N, M, R; 
	scanf("%d %d %d", &N, &M, &R); 

	// 동적 할당. 
	// 정점과 간선을 표현한 구조체배열 arr
	Node *arr = (Node *)malloc(sizeof(Node) * (N+1)); 
	for (int i = 1; i <= N; i++) {
		arr[i].next = NULL; 
	}

	// 방문 순서를 기록할 visitOrder
	int *visitOrder = (int *)calloc(N+1, sizeof(int)); 

	// 스택 이름: stack (Linked List)
	Stack *head = malloc(sizeof(Stack)); 
	Stack *tail = malloc(sizeof(Stack)); 

	// 입력 받기. 
	int from, to;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &from, &to); 
		insertNode(arr, from, to);  
	}

	// Node *target;
	// for (int i = 1; i <= N; i++) {
	// 	target = arr[i].next;
	// 	while (target != NULL) {
	// 		printf("target: %d\n", target -> number); 
	// 		target = target -> next;
	// 	} 
	// }

	// 스택에 쌓을 첫 번째 숫자. 
	Stack *firstNode = malloc(sizeof(Stack)); 
	firstNode -> next = tail; 
	firstNode -> number = R; 
	head -> next = firstNode; 
	tail -> next =  NULL;

	dfsSearch(arr, head, tail, visitOrder); 

	for (int i = 1; i <= N; i++) {
		printf("%d\n", visitOrder[i]); 
		// 모든 노드 해제.
		while (arr[i].next != NULL) {
			deleteNode(arr, i); 
		}

	}

	// 메모리 해제. 
	free(arr); free(visitOrder); 
	free(head); free(tail); 
}