//재귀함수가 뭔가요?

#include <stdio.h>
#include <string.h>

void printIt(int N, int i) {
	char str2[200] = "\"재귀함수가 뭔가요?\"\n";
	char str3[200] = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	char str4[200] = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	char str5[200] = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	char str6[200] = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	char str7[200] = "라고 답변하였지.\n";
 
 
 	//printf("I:: %d\n", i); 
	for (int j = 0; j < 4*i; j++) {
		printf("_");
	}
	printf("%s", str2);
	for (int j = 0; j < 4*i; j++) {
		printf("_");
	}
	printf("%s", str3);
	for (int j = 0; j < 4*i; j++) {
		printf("_");
	}
	printf("%s", str4);
	for (int j = 0; j < 4*i; j++) {
		printf("_");
	}
	printf("%s", str5); 
	//printf("I:: %d\n", i); 


	if (N == 1) {
		i++;
		for (int j = 0; j < 4*i; j++) {
			printf("_");
		}
		printf("%s", str2);
		for (int j = 0; j < 4*i; j++) {
			printf("_");
		}
		printf("%s", str6);
		for (int j = 0; j < 4*i; j++) {
			printf("_");
		}
		printf("%s", str7);
		return; 
	}
	printIt(N-1, ++i);
	for (int j = 0; j < 4*i; j++) {
		printf("_");
	}

	printf("%s", str7);

}

int main()
{
	int N, i = 0;
	scanf("%d", &N);
	char str1[100] = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	char str8[200] = "라고 답변하였지.";

	printf("%s", str1);
	printIt(N, i);
	printf("%s", str8);
}
