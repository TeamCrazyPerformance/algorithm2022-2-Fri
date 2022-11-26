#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef vector<int> vi;
typedef vector<vi> vvi;


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
		dfs(mR);

		for (int i = 1; i <= mN; i++)
			cout << mOrder[i] << "\n";
	}


private:
	void init()
	{
		int E;
		cin >> mN >> E >> mR;
		mEdges.resize(mN + 1);
		mOrder.resize(mN + 1);

		int s, d;
		while (E--)
		{
			cin >> s >> d;
			mEdges[s].push_back(d);
			mEdges[d].push_back(s);
		}

		for (auto& edges : mEdges)
			sort(edges.begin(), edges.end());
	}

	void dfs(int now)
	{
		mOrder[now] = mCnt++;
		for (auto next : mEdges[now])
		{
			if (mOrder[next] == 0)
			{
				dfs(next);
			}
		}
	}


private:
	vvi mEdges;
	vi	mOrder;
	int mN, mR, mCnt = 1;
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