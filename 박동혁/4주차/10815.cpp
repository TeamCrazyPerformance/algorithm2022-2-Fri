#include<iostream>
#include<algorithm>

using namespace std;

int card[500001];
pair<int, int> test_case[500001];
int ans[500001];

void search(int n, int m)
{
    int flag = 0;
    for(int i=0; i<n; i++) {
        int st = flag, end = m-1;
        while(st<=end) {
            int num = card[i];
            int mid = (st+end)/2;
            if(num < test_case[mid].first) end = mid-1;
            else if(num > test_case[mid].first) st = mid+1;
            else {
                ans[test_case[mid].second]++;
                flag = mid;
                break;
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> card[i];
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> test_case[i].first;
        test_case[i].second = i;
    }
    sort(card, card+n);
    sort(test_case, test_case+m);

    search(n, m);

    for(int i=0; i<m; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}