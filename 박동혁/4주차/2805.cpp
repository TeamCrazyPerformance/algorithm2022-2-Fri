#include<iostream>
#include<algorithm>

using namespace std;

int tree[1000001];
int bisearch(int n, int m)
{
    int st = 0, end = tree[n-1], ans=0;
    while(st<=end) {
        int mid = (st+end)/2;
        long long sum = 0;
        for(int i=n-1; i>=0; i--) {
            if(tree[i]-mid <= 0) break;
            sum += tree[i]-mid;
        }
        if(sum >= m) {
            ans = (mid > ans) ? mid : ans;
            st = mid+1;
        }
        else end = mid-1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> tree[i];
    }
    sort(tree, tree+n);

    cout << bisearch(n, m);
}