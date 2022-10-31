#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#define MAXSIZE 1000001
long long int list[MAXSIZE];
bool Sum_Check(long long int mid,long long int N, long long int M) {
	long long int sum=0;
	for (int i = 0; i < N; i++) {
		if (list[i] >= mid) sum += list[i] - mid;
	}
	if (sum >= M) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long int N; long long int M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> list[i];
	long long int start = 0, end = *max_element(list, list + N);
	while (start+1 < end) {
		long long int mid = (start + end) / 2;
		if (Sum_Check(mid, N, M)) start = mid;
		else end = mid;
	}
	cout << start;
}
