#include <iostream>
using namespace std;

int main() {
	char a[51][52];
	char b[51][52];
	int n, m, answer = 0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						if(a[k][l] == '1') a[k][l] = '0';
						else a[k][l] = '1';
					}
				}
				answer += 1;
			} else {
				continue;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}