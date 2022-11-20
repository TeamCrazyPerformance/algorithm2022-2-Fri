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
		cin >> temp;
		if(temp == 0) {
			if(pQ.empty())
				cout << "0\n";
			else {
				cout << pQ.top() << "\n";
				pQ.pop();
			}
		} else {
			pQ.push(temp);
		}
	}
	
	return 0;
}
