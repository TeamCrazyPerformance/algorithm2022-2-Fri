#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;


int jumpN[8] = { -2, -2, -1, -1, 2, 2, 1, 1 };
int jumpM[8] = { 1, -1, 2, -2, 1, -1, 2, -2 };


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
		int srcN, srcM, dstN, dstM;
		cin >> srcN >> srcM >> dstN >> dstM;
		bfs(srcN, srcM, dstN, dstM);

		cout << mChessboard[dstN][dstM] << "\n";
	}


private:
	void init()
	{
		cin >> mN;
		mChessboard.resize(mN, vi(mN));
	}

	void bfs(int srcN, int srcM, int dstN, int dstM)
	{
		queue<pii> box;
		box.push({ srcN, srcM });

		int nextN, nextM;
		while (!box.empty())
		{
			auto [nowN, nowM] = box.front();
			box.pop();
			if (nowN == dstN && nowM == dstM)
				break;

			int nextDepth = mChessboard[nowN][nowM] + 1;
			for (int i = 0; i < 8; i++)
			{
				nextN = nowN + jumpN[i];
				nextM = nowM + jumpM[i];

				if (rangeCheck(nextN, nextM) && mChessboard[nextN][nextM] == 0)
				{
					mChessboard[nextN][nextM] = nextDepth;
					box.push({ nextN, nextM });
				}
			}
		}
	}

	inline bool rangeCheck(int n, int m)
	{
		return (n >= 0) && (n < mN) && (m >= 0) && (m < mN);
	}


private:
	vector<vi> mChessboard;
	int mN;
};


int main()
{
	fastio;

	int T;
	//T = 1;
	cin >> T;

	while (T--)
	{
		Q q;
		q.Solve();
	}

	return 0;
}