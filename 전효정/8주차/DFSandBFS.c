// 인터넷에서 가지고 왔습니다.
// https://romanceboong.tistory.com/entry/C언어-BFS와-DFS

#include <stdio.h>

int Graph[1001][1001] = {0}; 
int DFSvisit[1001] = {0}; 
int BFSvisit[1001] = {0}; 
int queue[1001]; 

void DFS(int v, int N) {
	
	DFSvisit[v] = 1; 
	printf("%d\n", v); 

	for (int i = 1; i <= N; i++) {
		if (Graph[v][i] == 1 && DFSvisit[i] == 0)
			DFS(i, N); 
	}

	return; 
}

void BFS(int v, int N) {
	 int front = 0, rear = 0, Pop; 

	 queue[0] = v; 
	 rear++; 
	 BFSvisit[v] = 1; 
	 printf("%d\n", v); 


	 while (front < rear) {
	 	Pop = queue[front]; 
	 	front++; 

	 	for (int i = 1; i <= N; i++) {
	 		if (Graph[Pop][i] == 1 && BFSvisit[i] == 0) {
	 			printf("%d\n", i); 
	 			BFSvisit[i] = 1; 
	 			queue[rear] = i; 
	 			rear++; 
	 		}
	 	}
	 }

	 return; 
}

int main()
{
	int N, M, start; 
	int i, x, y; 

	scanf("%d %d %d", &N, &M, &start); 

	for (i = 0 ; i < M; i++) {
		scanf("%d %d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1; 
	}

	DFS(start, N); 
	printf("\n");
	BFS(start, N); 

	return 0; 
}
