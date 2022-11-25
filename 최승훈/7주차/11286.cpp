#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq1; // 양수 오름차순 저장
priority_queue<int> pq2; // 음수 내림차순 저장 절댓값이므로 내림차순

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			// 둘 다 비어있다면 0 출력
			if (pq1.empty() && pq2.empty()) 
				cout << "0\n";
			else // 둘 중 하나가 비어있거나 둘다 원소가 있거나
			{
				// 하나만 비어있을 때
				if (pq1.empty())
				{
					cout << pq2.top() << '\n';
					pq2.pop();
				}
				// 하나만 비어있을 때
				else if (pq2.empty())
				{
					cout << pq1.top() << '\n';
					pq1.pop();
				}
				// 둘 다 원소가 있을 때
				else
				{
					if (pq1.top() < -pq2.top()) // 음수이므로 -붙이기
					{
						cout << pq1.top() << '\n';
						pq1.pop();
					}
					else
					{
						cout << pq2.top() << '\n';
						pq2.pop();
					}
				}
			}
		}
		else if (num > 0) // 양수일 때
			pq1.push(num);
		else // 음수일 때
			pq2.push(num);
	}

}
