#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef vector<int> vi;

int N, M;
vi V;

void init(){
	cin >> N >> M;
	V.resize(0);
}

void backTracking(int X) {
	if (X == M+1) {
		for (int i : V) {
			cout << i << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			V.push_back(i);
			backTracking(X + 1);
			V.pop_back();
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	init();
	backTracking(1);
}
