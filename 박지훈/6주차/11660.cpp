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

	~Q()
	{

	}

	void Solve()
	{
		int x1, y1, x2, y2;
		while (mM--)
		{
			cin >> x1 >> y1 >> x2 >> y2;	// x1,x2 부터 x2,y2까지의 합을 반환
			cout << mDp[x2][y2] - mDp[x1 - 1][y2] - mDp[x2][y1 - 1] + mDp[x1 - 1][y1 - 1] << "\n";
		}
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mDp.resize(mN + 1, vi(mN + 1));

		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mN; j++)
			{
				cin >> mDp[i][j];	// mDp[i][j] = 1,1 부터 i,j까지의 합을 저장하는 2차원 배열
				mDp[i][j] += mDp[i][j - 1] + mDp[i - 1][j] - mDp[i - 1][j - 1];
			}
		}
	}


private:
	vvi mDp;
	int mN, mM;

};


int main()
{
	fastio;

	int T;
	T = 1;
	//cin >> T;
	//time_t start = clock();

	while (T--)
	{
		Q q;
		q.Solve();
	}

	//cout << "\n" << ld(clock() - start)/CLOCKS_PER_SEC;

	return 0;
}