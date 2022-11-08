#include<iostream>

using namespace std;

int arr[10];
bool checked[10];
int n, m;

void recur(int k)
{
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!checked[i]) {
            arr[k]=i;
            checked[i] = true;
            recur(k+1);
            
            checked[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    recur(0);
}