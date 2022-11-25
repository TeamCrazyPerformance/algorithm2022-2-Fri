#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    //int 저장되는 타입, vector는 배열이 저장되는 공간, greater는 오름차순
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            pq.push(num);
            // 전체 저장하면 메모리 초과가 뜬다 ㅠㅠ
            // N번째로 큰 수를 찾으면 되므로 N=5인 경우 5번째로 큰 수를 찾으면 된다.
            // 내림차순으로 5번째 수는 오름차순으로 26번째 수이다.
            // 가장 작은 수를 하나씩 제거해 오름차순으로 26번째 수를 찾는다.
            if (pq.size() > N) { 
                pq.pop();
            }
        }
    }

    cout << pq.top();
}
