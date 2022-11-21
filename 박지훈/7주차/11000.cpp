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
		auto cmp_abs = [](auto& a, auto& b) -> bool		// ���밪 �۰�, ������ ���� �켱
		{
			if (abs(a) == abs(b))
				return a > b;
			return abs(a) > abs(b);
		};
		priority_queue<int, vi, decltype(cmp_abs)> pq;
		int s, t, MaxLec = 0, nowLec = 0;

		for (int i = 0; i < mN; i++)
		{
			cin >> s >> t;
			pq.push(s);
			pq.push(-t);	// �ٸ� ���� ���� �ð����� ���� ������ �ð��� �켱�� �ǰ� ������ �ֱ�
		}

		while (!pq.empty())
		{
			if (pq.top() < 0)	// ���� ���� ���
				nowLec--;		// ���� ���ǽ� �ϳ� ���̱�
			else
			{					
				nowLec++;		// ���� ���ǽ� �ϳ� ���̱�
				MaxLec = max(MaxLec, nowLec);	// �ִ� ���ǽ� ����
			}

			pq.pop();
		}

		cout << MaxLec;
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