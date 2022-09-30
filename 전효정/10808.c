//<알파벳 개수>
#include <stdio.h>
#include <string.h>

int main()
{
	char str[101], alphabet[27] = {0};
	scanf("%s", str);
	int len = strlen(str);

	// a = 97

	for (int i = 0; i < len; i++) {
		alphabet[str[i] - 97]++;
	}

	for (int i = 0 ; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}

	
}
