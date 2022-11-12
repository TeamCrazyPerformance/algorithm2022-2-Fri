#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> stairs(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
	vector<pair<int, int>> C(N + 1);
	C[0] = { 0,0 };
	C[1] = { stairs[1] ,stairs[1] }; 
	C[2] = { stairs[2],stairs[2] + stairs[1] }; //{직전 칸을 건너뛴 경우, 건너뛰지 않은 경우}
	for (int i = 3; i <= N; i++) {
		C[i] = { stairs[i] + max(C[i - 2].first,C[i - 2].second), stairs[i] + C[i - 1].first };
	}
	cout << max(C[N].first, C[N].second);
}
