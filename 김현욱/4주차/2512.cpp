#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	vector<int> v;
	int n, m, temp;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	
	cin >> m;
	
	sort(v.begin(), v.end());
	
	int left = 0, right = v[v.size() - 1], mid, answer = 0;
	while(left <= right) {
		int sum = 0;
		mid = (left + right) / 2;
		for(int i = 0; i < n; i++)
			sum += min(v[i], mid);
		
		if (sum <= m) {
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	
	cout << answer;
	
	return 0;
}