#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, num;
	priority_queue <int, vector<int>, greater<int>> qg;
	priority_queue <int, vector<int>, less<int>> ql;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> num;
		
		if(i > 0 && num < qg.top()) {
			ql.push(num);
		} else {
			qg.push(num);
		}
		
		if(qg.size() > ql.size()) {
			ql.push(qg.top());
			qg.pop();
		}
		if(qg.size() < ql.size()) {
			qg.push(ql.top());
			ql.pop();
		}
		
		if(i & 1)
			cout << ql.top() << "\n";
		else
			cout << qg.top() << "\n";
	}
	
	return 0;
}
