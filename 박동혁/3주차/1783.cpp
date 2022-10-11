#include<iostream>

using namespace std;

int main()
{
    int n, m, cnt=1;
    cin >> n >> m;
    if(n==1 || m==1) {}
    else if(n==2) {
        cnt += ((m-1)/2 < 4) ? (m-1)/2 : 3;
    }
    else if(m>=7) {
        cnt = m-2;
    }
    else {
        cnt += ((m-1) < 4) ? (m-1) : 3;
    }
    cout << cnt;
}