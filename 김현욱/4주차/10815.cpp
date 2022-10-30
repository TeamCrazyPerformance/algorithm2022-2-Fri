#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> &v, int target) {
	int left = 0, right = v.size() - 1, mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if (v[mid] == target)
			return mid;
		else if (v[mid] > target)
			right = mid - 1;
		else if (v[mid] < target)
			left = mid + 1;
	}
	return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	vector<int> v;
	int n, m, num;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	cin >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> num;
		if(binary_search(v, num) == -1)
			cout << "0 ";
		else
			cout << "1 ";
	}
	
	return 0;
}