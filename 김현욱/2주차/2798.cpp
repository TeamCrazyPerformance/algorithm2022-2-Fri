#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, max = 0, arr[100];
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(i == j || j == k || k == i)
					continue;
					
				int sum = arr[i] + arr[j] + arr[k];
				if(sum > max && sum <= m)
					max = sum;
				if(sum == m) {
					cout << sum;
					return 0;
				}
			}
		}
	}
	
	cout << max;
	
	return 0;
}