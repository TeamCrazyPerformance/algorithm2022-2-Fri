#include<iostream>

using namespace std;

int main()
{
	int n, m, sum, ans=0;
	cin >> n >> m;
	int card[n+1];
	for(int i=0; i<n; i++)
		cin >> card[i];
	for(int i=0; i<n-2; i++) {
		for(int j=i+1; j<n-1; j++) {
			for(int k=j+1; k<n; k++) {
				sum = card[i]+card[j]+card[k];
				if(sum<=m && m-sum<m-ans) {
					ans=sum;
                }
			}
		}
	}
	cout << ans;

    return 0;
}