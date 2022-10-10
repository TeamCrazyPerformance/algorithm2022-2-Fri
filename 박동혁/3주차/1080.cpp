#include<iostream>

using namespace std;

int main()
{
    int n, m, cnt=0;
    cin >> n >> m;
    char arr1[n][m], arr2[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin >> arr1[i][j];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin >> arr2[i][j];
    }
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-2; j++) {
            if(arr1[i][j]!=arr2[i][j]) {
                for(int row=i; row<i+3; row++) {
                    for(int column=j; column<j+3; column++) {
                        if(arr1[row][column]=='0') {
                            arr1[row][column]='1';
                        } else {
                            arr1[row][column]='0';
                        }
                    }
                }
                cnt++;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr1[i][j]!=arr2[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << cnt;
}