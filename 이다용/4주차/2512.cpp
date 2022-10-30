#include <iostream>
#include <numeric>
#include <algorithm>
#define MAXSIZE 10001
using namespace std;
int list[MAXSIZE];
bool MAX_check(int max_line,int N,int M) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] >= max_line) sum += max_line;
		else sum += list[i];
	}
	if (sum <= M) return true;
	else return false;
}
int main() {
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	cin >> M;
	if (accumulate(begin(list), end(list), 0, plus<int>()) <= M) {
		cout << *max_element(list, list + N);
		return 0;
	}
	int start = 0, end = *max_element(list, list + N);
	while (start + 1 < end) {
		int mid = (start + end) / 2;
		if (MAX_check(mid,N,M)) start = mid;
		else end = mid;
	}
	cout << start;
}
