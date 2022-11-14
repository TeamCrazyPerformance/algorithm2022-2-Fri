#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int X1, X2, Y1, Y2;
int sum = 0;
vector<vector<int>> V_acc;
void init() {
	cin >> N >> M;
	V_acc.resize(N + 1, vector<int>(N + 1));
	int node;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> node;
			V_acc[i][j] = V_acc[i][j - 1] + node;
		}
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	init();
	for (int i = 0; i < M; i++) {
		sum = 0;
		cin >> X1 >> Y1 >> X2 >> Y2;
		for (int j = X1; j <= X2; j++) {
			sum += V_acc[j][Y2] - V_acc[j][Y1 - 1];
		}
		cout << sum << "\n";
	}
}
