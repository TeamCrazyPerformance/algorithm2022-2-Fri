#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int> > pq;
    int n, input;
    cin >> n;
    while(n--) {
        cin >> input;
        if(input != 0) {
            pq.push(input);
        }
        else if(pq.empty()) {
            cout << 0 << '\n';
        }
        else {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}