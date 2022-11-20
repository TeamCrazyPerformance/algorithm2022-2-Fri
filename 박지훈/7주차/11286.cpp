#include <iostream>
#include <vector>
#include <algorithm>
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
		// Priority Queue�� ���� �� �Լ�(����)
		auto cmp_abs = [](auto& child, auto& parent) -> bool		
		{
			if (abs(child) == abs(parent))
				return child > parent;
			return abs(child) > abs(parent);
		};
		priority_queue<int, vi, decltype(cmp_abs)> pq(cmp_abs);	// ������ cmp_abs�� ����ϴ� �켱���� ť
		int q;

		while (mN--)
		{
			cin >> q;
			if (q == 0)
			{
				if (pq.empty())
					cout << "0\n";
				else
				{
					cout << pq.top() << "\n";
					pq.pop();
				}
			}
			else
				pq.push(q);
		}
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