#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<vector<int>> V(21, vector<int>(21));
int MIN = 1000000;
int sum(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < v.size();i++) {
		for (int j = i; j < v.size();j++) {
			sum += V[v[i]][v[j]];
			sum += V[v[j]][v[i]];
		}
	}
	return sum;
}
void Group(vector<int> node, int M, vector<int> visited) {
	if (visited.size() == M) {
		for (int i : visited) {
			node.erase(remove(node.begin(), node.end(), i),node.end());
		}
		
		int s = abs(sum(visited) - sum(node));
		if (s < MIN) MIN = s;
	}
	else {

		for (int i = visited.back(); i < node.size();i++) {
			visited.push_back(node[i]);
			Group(node, M, visited);
			visited.pop_back();
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> V[i][j];
		}
	}
	vector<int> node;
	for (int i = 1; i <= N; i++) {
		node.push_back(i);
	}
	vector<int> visited;
	visited.push_back(1);
	Group(node, N / 2, visited);
	cout << MIN;
}
