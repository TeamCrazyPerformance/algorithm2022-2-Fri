#include<iostream>

using namespace std;

int n, cnt=0;
int attack[20][20];
void recur(int i)
{
    if(i==n+1) {
        cnt++;
        return;
    }
    for(int j=1; j<=n; j++) {
        if(attack[i][j] == 0) {
            attack[i][j]++;
            int tmp=1;
            for(int a=i+1; a<=n; a++, tmp++) {
                attack[a][j]++;
                if(j-tmp>0)
                    attack[a][j-tmp]++;
                if(j+tmp<=n)
                    attack[a][j+tmp]++;
            }
            recur(i+1);
            attack[i][j]--;
            tmp=1;
            for(int a=i+1; a<=n; a++, tmp++) {
                attack[a][j]--;
                if(j-tmp>0)
                    attack[a][j-tmp]--;
                if(j+tmp<=n)
                    attack[a][j+tmp]--;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    recur(1);
    cout << cnt;
}