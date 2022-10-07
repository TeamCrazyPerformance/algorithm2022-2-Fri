#include <stdio.h>
#include <stdlib.h>

struct Snake {
	struct Snake *next;
	struct Snake *prev; 
	int row;
	int col; 
};

void removeNode(struct Snake *head, struct Snake *tail){
	if (tail -> next == head) return; 
	struct Snake *target = tail -> next;

	tail -> next = target -> next;
	free(target); 
}

void insertHead(int headRow, int headCol, struct Snake *head, struct Snake *tail){
	struct Snake *newNode = malloc(sizeof(struct Snake));
	struct Snake *target = head -> prev;

	newNode -> row = headRow;
	newNode -> col = headCol;

	target -> next = newNode;
	newNode -> prev = target;
	newNode -> next = head;
	head -> prev = newNode; 
}

void updateTail(struct Snake *tail, struct Snake *head){

	if (tail -> next == head) return; 
	struct Snake *target = tail -> next;

	if(target -> next == head) {
		return; 
	}

	tail -> next = target -> next;
	free(target); 
}

int gameDummy(int **dummy, int N, int *directionX, char *directionC)
{
	int time = 0, index = 0;
	// right = 0, down = 1, left = 2, up = 3
	int rdlu = 0; 

	struct Snake *tail = malloc(sizeof(struct Snake));
	struct Snake *head = malloc(sizeof(struct Snake));

	tail -> next = head;
	head -> next = NULL;
	tail -> prev = NULL;
	head -> prev = tail;
	// head and tail of the snake.
	int headRow = 1, headCol = 1, tailRow = 1, tailCol = 1; 
	dummy[1][1] = 1; 
	insertHead(1, 1, head, tail); 


	while (1) {
		//printf("index: %d\n", index);
		if (directionX[index] == time) {
			// 뱀이 오른쪽으로 꺾을 때. 
			if (directionC[index] == 'D') {
				rdlu++;
				if (rdlu > 3) rdlu = 0;				
			}
			// 뱀이 왼쪽으로 꺾을 때.  
			else if (directionC[index] == 'L') {
				rdlu--;
				if (rdlu < 0) rdlu = 3;
			}
			index++; 
		}


		// 뱀의 머리가 움직임.
		switch (rdlu) {
			case 0:
				headCol++;	
				break;
			case 1:
				headRow++;
				break;
			case 2:
				headCol--;
				break;
			case 3:
				headRow--;
				break;
		}

		// 뱀의 머리가 움직이면, 시간은 증가한다. 
		time++;

		// 1. 뱀의 머리가 벽에 닿았을 때, 즉 배열의 범위를 넘어갔을 때. 2. 뱀의 머리가 자신의 몸에 닿았을 때 게임은 끝난다. 
		if (headRow > N || headCol > N || headRow < 1 || headCol < 1 || dummy[headRow][headCol] == 1){
			while (tail -> next != head) {
				removeNode(head, tail);
			}
			free(head);
			free(tail); 
			return time;
		} 

		// 게임이 끝나지 않았다면, 새로운 머리 노드를 큐에 추가한다. 
		insertHead(headRow, headCol, head, tail);

		// 사과를 먹지 않았다면, head를 움직이고 현재 꼬리는 0이 되어야 한다.
		if (dummy[headRow][headCol] != 2){
			dummy[headRow][headCol] = 1;
			// 기존의 꼬리 좌표는 0으로 초기화.
			dummy[tailRow][tailCol] = 0;
	
			// 큐에서 현재 tail 에 있는 노드를 삭제하고, 다음 노드의 좌표를 현재 꼬리의 좌표로 업데이트 한다.
			updateTail(tail, head);
			// 뱀의 새로운 꼬리 좌표를 연결 리스트 스택에서 찾아냄.
			tailRow = tail -> next -> row;
			tailCol = tail -> next -> col;
		} 
		//  
		else {
			dummy[headRow][headCol] = 1;
		}	
	}
}


int main()
{
	int N, K, L, X;
	char C;
	scanf("%d", &N); 

	// dummy board 생성.
	int **dummy = (int **)malloc(sizeof(int *) * (N+2));

	for (int i = 0; i < N+2; i++) {
		dummy[i] = (int *)calloc(N+2, sizeof(int)); 
	}


	int row, col; 

	// dummy board 에 사과 넣기. 
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &row, &col); 
		dummy[row][col] = 2; 
	}

	// direction 변환.
	// 방향 변환 동적 할당 배열.
	scanf("%d", &L);
	int *directionX = (int *)malloc(sizeof(int) * L);
	char *directionC = (char *)malloc(sizeof(char) * L); 
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &X, &C);
		directionX[i] = X;
		directionC[i] = C;
	}


	// game start.
	printf("%d", gameDummy(dummy, N, directionX, directionC)); 

	for (int i = 0; i < N+2; i++) {
		free(dummy[i]); 
	}

	free(dummy); 
	free(directionX);
	free(directionC);

}