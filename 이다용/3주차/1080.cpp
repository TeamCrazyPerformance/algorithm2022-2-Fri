#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<char>> A(N, vector<char>(M, '0'));
	vector<vector<char>> B(N, vector<char>(M, '0'));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i+3 <= N; i++) {
		for (int j = 0; j+3 <= M; j++) {
			if (A[i][j] != B[i][j]) {
				ans++;
				for (int k = 0; k < 3; k++) {
					for (int s = 0; s < 3; s++) {
						if (A[i+k][j+s] == '1')A[i+k][j+s] = '0';
						else A[i+k][j+s] = '1';
					}
				}
			}
		}
	}

	if (A == B) {
		cout << ans;
		return 0;
	}

	cout << -1;


}
