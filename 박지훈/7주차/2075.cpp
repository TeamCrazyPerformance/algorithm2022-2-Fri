#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef vector<int> vi;


class Q
{
public:
	Q()
	{
		init();
	}

	~Q() {}

	void Solve()
	{
		priority_queue<int, vi, greater<int> > pq;	// 최소힙
		int num;
		for (int i = 0; i < mN; i++)
		{
			cin >> num;
			pq.push(num);				// 먼저 mN개 만큼 넣어주기, top에는 항상 현재까지 받은 수 중 mN번째 큰 수가 저장되게 할 것임
		}

		for (int i = 1; i < mN; i++)
		{
			for (int j = 0; j < mN; j++)
			{
				cin >> num;
				if (pq.top() < num)		// 새로운 수가 mN번째 큰 수보다 크면
				{
					pq.pop();			// 현재 mN번째 큰 수는 mN + 1번째가 되니 pop,
					pq.push(num);		// 새로운 수를 push 해주기
				}
			}
		}

		cout << pq.top();
	}


private:
	void init()
	{
		cin >> mN;
	}



private:
	int mN;

};


int main()
{
	fastio;

	int T;
	T = 1;
	//cin >> T;

	while (T--)
	{
		Q q;
		q.Solve();
	}

	return 0;
}