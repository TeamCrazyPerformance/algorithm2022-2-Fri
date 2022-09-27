#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, total_length=0, length=1, tmp=10;
    cin >> n;

    for(int i=1; i<=n; i++) {
        if(i==tmp) {
            tmp *= 10;
            length++;
        }
        total_length += length;
    }
    cout << total_length;
}