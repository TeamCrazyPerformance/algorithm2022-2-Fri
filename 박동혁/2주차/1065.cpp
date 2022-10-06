#include<iostream>

using namespace std;

int main()
{
    int n, cnt=0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        if(i<100) {
            cnt++;
            continue;
        }
        int tmp = i, mod = tmp%10;
        bool flag = true;
        tmp /= 10;
        int d1 = mod - (tmp%10);
        mod = tmp%10;
        while(tmp/=10) {
            int d2 = mod - (tmp%10);
            mod = tmp%10;
            if(d1!=d2) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cnt++;
        }
    }
    cout << cnt;
}