#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, answer = 0;
	int idx[26] = {};
	
	cin >> n;
	string arr[100];
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	for(int i = 0; i < n; i++) {
		bool satisfy = true;
		for(int j = 0; j < 26; j++)
			idx[j] = -1;
		
		for(int j = 0; j < arr[i].length(); j++) {
			int c = arr[i].at(j) - 'a';
			if (idx[c] == -1 || idx[c] == j - 1)
				idx[c] = j;
			else
				satisfy = false;
		}
		
		if(satisfy) answer++;
	}
	
	cout << answer;
	
	return 0;
}