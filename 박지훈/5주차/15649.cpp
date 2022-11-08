#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
typedef long long ll;
typedef vector<int> vi;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		backTracking(0);
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mSeq.resize(mM);
		mCheck.resize(mN + 1);
	}

	void backTracking(int now)
	{
		if (now == mM)
		{
			for (int num : mSeq)
				cout << num << " ";
			cout << "\n";
			return;
		}

		int next = now + 1;
		for (int i = 1; i <= mN; i++)
		{
			if (mCheck[i] >= 0)
			{
				mCheck[i] = -1;
				mSeq[now] = i;

				backTracking(next);

				mCheck[i] = 0;
			}
		}
	}



private:
	vi mSeq, mCheck;
	int mN, mM;
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