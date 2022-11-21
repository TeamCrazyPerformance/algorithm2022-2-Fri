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
    priority_queue<int, vector<int>, greater<int> > pq;

    pq.push(-2000000000);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> input;
            if(input > pq.top()) pq.push(input);
            if(pq.size() > n) pq.pop();
        }
    }
    cout << pq.top();
}