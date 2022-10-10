#include<iostream>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> &t1, pair<int, int> &t2)
{
    if(t1.second == t2.second)
        return t1.first < t2.first;
    return t1.second < t2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    pair<int, int> time[n];
    for(int i=0; i<n; i++) {
        cin >> time[i].first >> time[i].second;
    }
    sort(time, time+n, compare);
    int cnt=1, end_time = time[0].second;
    for(int i=1; i<n; i++) {
        if(end_time > time[i].first ) {
            continue;
        }
        end_time = time[i].second;
        cnt++;
    }
    cout << cnt;
}