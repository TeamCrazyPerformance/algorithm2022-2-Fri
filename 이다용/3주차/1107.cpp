#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool hasBrokenButton(vector<int> V, int N) {
	if (N == 0) {
		if (find(V.begin(), V.end(), N % 10) != V.end()) return true;
	}
	while (N != 0) {
		if (find(V.begin(), V.end(), N % 10) != V.end()) return true;
		N /= 10;
	}
	return false;
}
int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;
	vector<int> V(M);
	for (int& elem : V) cin >> elem;
	if (N == 100) {
		cout << 0;
		return 0;
	}
	
	int N_min = abs(N - 100);
	if (M == 10) {
		cout << N_min;
		return 0;
	}
	int i = 0, j = 0;
	int N_up = N;
	int N_down = N;
	while (hasBrokenButton(V, N_up) == true&&j<=N_min){
		N_up++;
		j++;
	}
	int up_min = 0; int temp = N_up;
	if (temp == 0)up_min++;
	while (temp != 0) {
		temp /= 10;
		up_min++;
	}
	up_min += abs(N_up - N);
	while (hasBrokenButton(V, N_down) == true && i <= N_min) {
		N_down--;
		i++;
	}
	int down_min = 0; temp = N_down;
	if (temp == 0)down_min++;
	while (temp != 0) {
		temp /= 10;
		down_min++;
	}
	if (N_down < 0)down_min = 500001;
	down_min += abs(N - N_down);
	cout << min({ N_min,down_min,up_min });

}
