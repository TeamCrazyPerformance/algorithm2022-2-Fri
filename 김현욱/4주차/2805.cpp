
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	vector<long long> v;
	long long n, m, temp;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());
	
	long long left = 0, right = v[v.size() - 1], mid, answer = 0;
	while(left <= right) {
		mid = (left + right) / 2;
		long long sum = 0;
		for(int i = 0; i < n; i++) {
			if (v[i] - mid > 0)
				sum += v[i] - mid;
		}
		
		if (sum > m) {
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		} else if (sum < m)
			right = mid - 1;
		else {
			answer = mid;
			break;
		}
	}
	
	cout << answer;
	
	return 0;
}