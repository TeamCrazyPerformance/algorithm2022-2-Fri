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
		auto cmp_abs = [](auto& a, auto& b) -> bool		// 절대값 작고, 같으면 음수 우선
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
			pq.push(-t);	// 다른 강의 시작 시간보다 강의 끝나는 시간이 우선이 되게 음수로 넣기
		}

		while (!pq.empty())
		{
			if (pq.top() < 0)	// 강의 끝인 경우
				nowLec--;		// 현재 강의실 하나 줄이기
			else
			{					
				nowLec++;		// 현재 강의실 하나 늘이기
				MaxLec = max(MaxLec, nowLec);	// 최대 강의실 갱신
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