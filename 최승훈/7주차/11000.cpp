#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, T, answer = 1;
// 시작시간, 종료시간
priority_queue<int> Class;
vector<pair<int, int>> class_time;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        class_time.push_back(make_pair(S, T));
    }

    sort(class_time.begin(), class_time.end());
    // 종료 시간이 빠를 수록 우선순위가 높도록 -를 붙여 push해준다.
    for (int i = 0; i < N; i++) {
        // 강의실이 다 비어있는 경우
        if (Class.empty()) {
            Class.push(-class_time[i].second);
        }
        else {
            // 강의실이 일부만 사용되는 경우 (큐에서 전부 차있는 경우)
            if (-Class.top() <= class_time[i].first) {
                Class.pop();
                Class.push(-class_time[i].second);
            }
            // 강의실이 전부 찬 경우
            else {
                answer++;
                Class.push(-class_time[i].second);
            }

        }
    }

    cout << answer << '\n';
}
