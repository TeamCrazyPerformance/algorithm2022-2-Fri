#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
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

		cout << mAns;
	}


private:
	void init()
	{
		cin >> mN;
		mNm1 = mN - 1;
		mAns = 0;

		mY.resize(mN);
		mDia1.resize((mN << 1) - 1);
		mDia2.resize((mN << 1) - 1);
	}

	void backTracking(int x)
	{
		if (x == mN)
		{
			mAns++;
			return;
		}

		int nextX = x + 1;
		for (int y = 0; y < mN; y++)
		{
			if (mY[y] == 0 && mDia1[y + x] == 0 && mDia2[mNm1 + y - x] == 0)
			{
				mY[y] = mDia1[y + x] = mDia2[mNm1 + y - x] = -1;

				backTracking(nextX);

				mY[y] = mDia1[y + x] = mDia2[mNm1 + y - x] = 0;
			}
		}
	}


private:
	vi mY, mDia1, mDia2;
	int mN, mNm1, mAns;
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