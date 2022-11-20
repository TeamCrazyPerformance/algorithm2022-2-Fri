#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue< int, vector<int>, greater<int> > pQ;
	int N, temp;
	
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> temp;
			pQ.push(temp);
			
			if(pQ.size() == N + 1)
				pQ.pop();
		}
	}
	
	cout << pQ.top();
	
	return 0;
}
