#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int s, t;
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> s >> t;
		v.push_back(make_pair(s, t));
	}
	
	sort(v.begin(), v.end());
	
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(v[0].second);
	for(int i = 1; i < N; i++) {
		s = v[i].first;
		t = v[i].second;
		int last = q.top();
		if(last > s)
			q.push(t);
		else {
			q.pop();
			q.push(t);
		}
	}
	
	cout << q.size();
	
	return 0;
}
