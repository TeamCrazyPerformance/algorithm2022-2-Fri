#include <stdio.h>
#include <stdlib.h>

void swap(int *queue, int a, int b) {
	int temp = queue[a];
	queue[a] = queue[b];
	queue[b] = temp;
}

void bubbleUp(int *queue, int order)
{
	
	while (order != 1) {
		// 왼쪽 child 노드
		if (order % 2 == 0) {
			if (queue[order/2] > queue[order]) {
				swap(queue, order/2, order);
				order = order/2;
			} else break;
		} else if (order % 2 == 1) {  // 오른쪽 child 노드
			if (queue[(order - 1)/2] > queue[order]) {
				swap(queue, (order-1)/2, order);
				order = (order - 1) / 2; 
			} else break;
		}
	}
	
}

void bubbleDown(int *queue, int order)
{
	int i = 1, small, child1, child2;
	queue[1] = queue[order];
	queue[order] = 0; 
	order--;

	while (1){

		if (order == 1) break;
		else if (order == 2) {
			if (queue[1] > queue[2]) swap(queue, 1, 2);
			break;
		}

		child1 = 2*i;
		child2 = 2*i + 1;

		if (child1 > order) break;
		else if (child1 == order) {
			if (queue[i] > queue[child1]) swap(queue, i, child1);
			small = child1; 
		} else if (child2 <= order && queue[child1] == 0) {
			if (queue[i] > queue[child2]) swap(queue, i, child2);
			small = child2;
		} else if (queue[child1] != 0 && queue[child2] != 0) {
			small = queue[child1] <= queue[child2] ? child1 : child2;
			if (queue[i] > queue[small]) swap(queue, i, small);
		} else break;

		i = small;
	}
}

void insertNode(int *queue, int new, int order) 
{
	queue[order] = new;
	bubbleUp(queue, order);
}

int removePeek(int *queue, int order)
{
	int peek = queue[1];
	bubbleDown(queue, order);

	return peek;
}

int main()
{
	int N, order = 0, result, num;
	scanf("%d", &N);
	int *queue = calloc(N+1, sizeof(int));

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num);
		if (order == 0 && num == 0) result = 0;
		else if (num == 0) {
			result = removePeek(queue, order);
			order--;
		} else {
			order++;
			insertNode(queue, num, order);
			continue;
		}
		printf("%d\n", result);
	}

}