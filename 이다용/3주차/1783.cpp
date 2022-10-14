#include <iostream>
using namespace std;

    int main() {
	int N, M;
	cin >> N >> M;
	int visit = 1;
	int K_x = 1, K_y = 1;
	if (N == 1||M==1) {
		cout << visit; 
		return 0;
	}
	if (M <= 6) {
		while (K_x < M) {
			if (K_y <= N / 2) {
				if (N - K_y == 1) {
					if (K_x == M - 1) break;
					K_x += 2;
					K_y++;
				}
				else {
					K_x++;
					K_y += 2;
				}
			}
			else {
				if (K_y == 1 ||N==2) {
					if (K_x == M - 1) break;
					K_x += 2;
					K_y--;
				}
				else {
					K_x++;
					K_y -= 2;
				}
			}
			visit++;
			if (visit == 4) break;
		}
	}
	else {
		if (N == 2) { 
			visit = 4;
			cout << visit;
			return 0;
		}
		visit = 5; K_x = 7;
		while (K_x < M) {
			if (K_y <= N / 2) {
				if (N - K_y == 1) {
					if (K_x == M - 1) break;
					K_x += 2;
					K_y++;
				}
				else {
					K_x++;
					K_y += 2;
				}
			}
			else {
				if (K_y == 1) {
					if (K_x == M - 1) break;
					K_x += 2;
					K_y--;
				}
				else {
					K_x++;
					K_y -= 2;
				}
			}
			visit++;
		}
	}
	cout << visit;
}
