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
    priority_queue<int, vector<int>, greater<int> > pq_pos;
    priority_queue<int, vector<int>, less<int> > pq_neg;
    for(int i=0; i<n; i++) {
        cin >> input;
        if(input > 0) pq_pos.push(input);
        else if(input < 0) pq_neg.push(input);
        else {
            if(pq_pos.empty() && pq_neg.empty()) cout << 0 << '\n';
            else if(pq_pos.empty()) {
                cout << pq_neg.top() << '\n';
                pq_neg.pop();
            }
            else if(pq_neg.empty()) {
                cout << pq_pos.top() << '\n';
                pq_pos.pop();
            }
            else {
                if(pq_pos.top() < abs(pq_neg.top())) {
                    cout << pq_pos.top() << '\n';
                    pq_pos.pop();
                }
                else {
                    cout << pq_neg.top() << '\n';
                    pq_neg.pop();
                }
            }
        }
    }
}