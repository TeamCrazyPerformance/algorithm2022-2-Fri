#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>
#include <queue>
using namespace std;
void Search(vector<int> node, int M, queue<int> visited) {
	if (visited.size() == M) {
		int a = visited.size();
		for (int i = 0; i < a; i++) {
			cout << visited.front() << " ";
			visited.pop();
		}
		cout << "\n";
	}

	else {
		for (int i = 0; i < node.size(); i++) {
			queue<int> visited2 = visited;
			vector<int> node2 = node;
			visited2.push(node[i]);
			node2.erase(remove(node2.begin(), node2.end(), node[i]));
			Search(node2, M, visited2);
			node2.clear();
		}
	}
}
int main() {
	int N, M; cin >> N >> M;
	vector<int> node;
	for (int i = 1; i <= N; i++) {
		node.push_back(i);
	}
	queue<int> visited;
	Search(node, M, visited);
}
