#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <pair<int, int> > time;
    priority_queue<int, vector<int>, greater<int> > pq;
    int a, b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        time.push_back(make_pair(a,b));
    }
    sort(time.begin(), time.end());

    pq.push(time[0].second);
    for(int i=1; i<n; i++) {
        if(time[i].first >= pq.top()) {
            pq.pop();
            pq.push(time[i].second);
        } 
        else pq.push(time[i].second);
    }
    cout << pq.size();
}