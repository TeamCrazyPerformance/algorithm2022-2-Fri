#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		backTracking(0, 0);

		cout << mAns;
	}


private:
	void init()
	{
		cin >> mN;
		mHalfN = mN >> 1;
		mTeam.resize(2);
		mTable.resize(mN, vi(mN));
		for (auto& row : mTable)
			for (auto& i : row)
				cin >> i;
	}

	void backTracking(int n, int tot)
	{
		if (n == mN)
		{
			mAns = min(mAns, abs(tot));
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			if (mTeam[i].size() < mHalfN)
			{
				int var = update(i, n);
				mTeam[i].push_back(n);

				if (i & 1)
					backTracking(n + 1, tot - var);
				else
					backTracking(n + 1, tot + var);

				mTeam[i].pop_back();
			}
		}
	}

	inline int update(int team, int n)
	{
		int tot = 0;
		for (auto member : mTeam[team])
			tot += mTable[n][member] + mTable[member][n];

		return tot;
	}


private:
	vvi mTable, mTeam;
	int mN, mHalfN, mAns = 0x7FFFFFFF;
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