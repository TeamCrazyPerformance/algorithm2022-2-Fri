#include<iostream>

using namespace std;

int main()
{
    int n, result=0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int tmp = i, sum = i;
        while(tmp!=0) {
            sum += tmp%10;
            tmp/=10;
        }
        if(sum==n) {
            result = i;
            break;
        }
    }
    cout << result;
    return 0;
}