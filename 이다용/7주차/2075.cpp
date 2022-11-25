#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int N,pos;
long int input;
vector<long int> heap;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

void init() {
	cin >> N;
	heap.push_back(0);
}

int main() {
	fastIO();
	init();
	for (int i = 0; i < N * N; i++)
	{
		cin >> input;
		heap.push_back(input);
		pos = heap.size() - 1;
		while (pos > 1 && heap[pos] < heap[pos / 2]) {
			swap(heap[pos], heap[pos / 2]);
			pos /= 2;
		}
		if (heap.size() == N + 2) {
			swap(heap[1], heap[heap.size() - 1]);
			heap.pop_back();
			int pos = 1;
			while (pos * 2 < heap.size()) {
				long int smallChild = heap[pos * 2];
				int smallChildPos = pos * 2;

				if (smallChildPos + 1 < heap.size() && smallChild > heap[smallChildPos + 1]) {
					smallChild = heap[pos * 2 + 1];
					smallChildPos = pos * 2 + 1;
				}
				if (heap[pos] < heap[smallChildPos]) break;
				swap(heap[pos], heap[smallChildPos]);
				swap(pos, smallChildPos);
			}
		}
	}
	cout << heap[1];
}
