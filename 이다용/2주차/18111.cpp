#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 501

int main() {
	int M, N, B, map[MAX][MAX], min_T = 2147483647, min_B;
	cin >> M >> N >> B; int temp=B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int std_B = 0; std_B <= 256; std_B++) {
		int T = 0; B = temp;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
				if (map[i][j] > std_B) { B += map[i][j] - std_B; T += 2 * (map[i][j] - std_B); }
				if (map[i][j] < std_B) { B -= std_B - map[i][j]; T += std_B - map[i][j]; }

			}
		}
		if (B<=64*pow(10,7)&&B >= 0 && T <= min_T) { min_T = T; min_B = std_B; }
	}
	cout << min_T << " " << min_B;
}

