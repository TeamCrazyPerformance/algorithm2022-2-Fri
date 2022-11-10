#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
typedef vector<vector<bool>> vvi;
vvi board;
int Count = 0;
void check(vvi V, int N, int x) {
	if (x == N - 1) {
		for (vector<bool> i : V) { //마지막 보드에 남은 빈칸 만큼 count+1
			if (!i[N - 1]) {
				Count++;
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!V[i][x]) {
				vvi V2 = V;
				fill(V2[i].begin(), V2[i].end(), true);
				int X = x, Y = 0;
				while (X < N - 1) {
					X++; Y++;
					if(Y+i<=N-1)V2[i+Y][X] = true;
					if(i-Y>=0)V2[i-Y][X] = true;
				}

				int x2 = x + 1;
				check(V2, N, x2);
			}
		}
	}
}
int main() {
	int N; cin >> N;
	clock_t start, finish;
	start = clock();
	board.resize(N, vector<bool>(N, false)); //false: 둘 수 있음, true: 없음
	int x = 0;
	check(board, N, x);
	cout << Count<<" ";
	finish = clock();
	cout << (double)(finish - start) / CLOCKS_PER_SEC << "초";
}
