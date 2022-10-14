//https://javachoi.tistory.com/295

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> &l, const pair<int, int> &r) {
	if (l.second == r.second)
		return l.first < r.first;
	else
		return l.second < r.second;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<pair<int, int>> v;
	int n, start, end, last = 0, count = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < n; i++) {
		if(v[i].first >= last) {
			count++;
			last = v[i].second;
		}
	}
	
	cout << count;
	
	return 0;
}