#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	//int 저장되는 타입, vector는 배열이 저장되는 공간, greater는 오름차순
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;
		// 0인 경우
		if (num == 0) {
			if (pq.empty()) // 비어있는 경우 0 출력
				cout << "0" << "\n";
			else { // 비어 있지 않을 때 queue에서 출력 후 삭제
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		//0이 아닐 때 queue에 숫자 넣어주기
		else 
			pq.push(num);
	}
}
