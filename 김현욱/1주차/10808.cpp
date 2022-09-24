#include <iostream>
#define LETTER 26
#define MAX_LENGTH 101
using namespace std;

int main() {
	int cnt[LETTER] = {};
	char str[MAX_LENGTH];
	cin >> str;
	
	for(int i = 0; i < MAX_LENGTH; i++) {
		if(str[i] == '\0') break;
		cnt[str[i] - 'a']++;
	}
	
	for(int i = 0; i < LETTER; i++)
		cout << cnt[i] << " ";
	
	return 0;
}