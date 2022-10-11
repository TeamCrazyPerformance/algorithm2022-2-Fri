#include<iostream>

using namespace std;

int gate[100001];
int dock[100001];

int getParent(int x)
{
    if(dock[x]==x) return x;
    return dock[x] = getParent(dock[x]);
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if(a < b) dock[b]=a;
    else dock[a]=b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int g, p, cnt=0;
    cin >> g >> p;
    for(int i=0; i<p; i++)
        cin >> gate[i];
    for(int i=1; i<=g; i++)
        dock[i] = i;
    
    for(int i=0; i<p; i++) {
        if(getParent(gate[i]) == 0) break;
        else {
            unionParent(gate[i], getParent(gate[i])-1);
            cnt++;
        }
    }
    cout << cnt;
}