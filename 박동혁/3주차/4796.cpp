#include<iostream>

using namespace std;

int main()
{
    int l, p, v, cnt=0;
    while(cin >> l >> p >> v) {
        if(l==0 && p==0 && v==0) {
            return 0;
        }
        cnt++;
        int ans = v/p * l;
        ans += (v%p > l) ? l : v%p;
        
        cout << "Case " << cnt << ": " << ans << '\n';
    }
}