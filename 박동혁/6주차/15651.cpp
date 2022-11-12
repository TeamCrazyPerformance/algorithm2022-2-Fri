#include<iostream>

using namespace std;

int n, m;
int arr[10];
void recur(int k)
{
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++) {
        arr[k]=i;
        recur(k+1);
    }
}

int main()
{
    cin >> n >> m;
    recur(0);
}