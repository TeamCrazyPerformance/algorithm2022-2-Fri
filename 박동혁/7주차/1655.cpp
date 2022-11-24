#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, input;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq_min;
    priority_queue<int, vector<int>, less<int> > pq_max;
    
    cin >> input;
    pq_max.push(input);
    cout << input << '\n';
    for(int i=1; i<n; i++) {
        cin >> input;
        if(pq_max.size() == pq_min.size()) {
            pq_max.push(input);
        } else {
            pq_min.push(input);
        }
        if(pq_max.top() > pq_min.top()) {
            int a = pq_max.top();
            int b = pq_min.top();
            pq_max.pop();
            pq_min.pop();
            pq_max.push(b);
            pq_min.push(a);
        }
        cout << pq_max.top() << '\n';
    }
}