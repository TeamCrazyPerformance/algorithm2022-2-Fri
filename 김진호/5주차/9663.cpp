#include <iostream>

#define MAX 15
using namespace std;

int N;
int cnt;
int chess[MAX];

bool isPromising(int n) {
	for (int i = 0; i < n; i++) {
		if (chess[i] == chess[n] || chess[i] - chess[n] == i - n || chess[i] - chess[n] == n - i)
			return false;
	}
	return true;
}

void rec(int num, int n) {
	if (num == N) {
		cnt++;
		return ;
	}
	for (int i = 0; i < N; i++) {
		chess[n] = i;

		if (isPromising(n))
			rec(num + 1, n + 1);
	}
}

void solve() {
	cin >> N;

	rec(0, 0);
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}