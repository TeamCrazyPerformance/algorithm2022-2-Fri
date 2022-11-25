#include<iostream>
#include<vector>
#include<algorithm>
#include <utility>
using namespace std;

vector<long int> heap;
int N;
long int input;
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
	for (int i = 0; i < N; i++) { 
		cin >> input;
		if (input > 0) { //insert
			heap.push_back(input);
			int pos = heap.size() - 1;
			while (pos > 1 && heap[pos] < heap[pos / 2]) {
				swap(heap[pos], heap[pos / 2]);

				pos /= 2;
			}
		}
		else { //delete
			if (heap.size() - 1 < 1) {
				cout << 0<<"\n";
				continue;
			}
			cout << heap[1] << "\n";
			swap(heap[1], heap[heap.size() - 1]);
			heap.pop_back();
			int pos = 1;
			while (pos * 2 < heap.size()){
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
}
