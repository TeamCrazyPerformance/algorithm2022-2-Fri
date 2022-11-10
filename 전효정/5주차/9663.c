// 백트래킹 문제...
// [바킹독의 실전 알고리즘] 0x0C강 - 백트래킹
// 코드를 가져옴.

#include <stdio.h>

int isused1[40] = {0};
int isused2[40] = {0};
int isused3[40] = {0}; 

int cnt = 0; 
int n; 
void func(int curr) {
	if (curr == n) {
		cnt++; 
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[i+curr] || isused3[curr-i+n-1]) 
			continue; 
		isused1[i] = 1; 
		isused2[i+curr] = 1; 
		isused3[curr-i+n-1] = 1; 
		func(curr+1); 
		isused1[i] = 0; 
		isused2[i+curr] = 0; 
		isused3[curr-i+n-1] = 0; 
	}
}

int main(void) {
	scanf("%d", &n);
	func(0); 
	printf("%d\n", cnt);  
}