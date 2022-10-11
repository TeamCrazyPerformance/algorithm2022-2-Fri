#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int make(vector<vector<unsigned int>>& V)
{
	vector<vector<unsigned int>> A;
	A.push_back(V[0]);
	for (int i = 1; i < V.size(); i++) {
		if (V[i][1] >= A.back()[0]){
			A.push_back(V[i]);
	}
	}
	
	return A.size();
}

int main() {
	int n; cin >> n;
	vector<vector<unsigned int>> V(n, vector<unsigned int>(2, 0));
	for (int i = 0; i < n; i++) {
		cin >>V[i][1]>>V[i][0];
	}
	sort(V.begin(), V.end());

	cout << make(V);
}
