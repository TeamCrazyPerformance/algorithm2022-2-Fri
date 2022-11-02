#include<iostream>
#include<algorithm>

using namespace std;

int req[10001];

int bisearch(int n, int b)
{
    int st = 0, end = req[n-1], ans;
    while(st<=end) {
        int mid = (st+end)/2, sum = 0;
        for(int i=0; i<n; i++) {
            sum += (mid < req[i]) ? mid : req[i];
        }
        if(sum < b) {
            ans = mid;
            st = mid+1;
        }
        else if(sum > b) end = mid-1;
        else return mid;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, budget, sum=0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> req[i];
    }
    cin >> budget;

    sort(req, req+n);

    cout << bisearch(n, budget);
}