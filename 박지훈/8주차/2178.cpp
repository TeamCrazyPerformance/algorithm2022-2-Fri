#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;


int jumpN[4] = { 0, 0, 1, -1 };
int jumpM[4] = { -1, 1, 0, 0 };

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
		bfs(1, 1);

		cout << mMaze[mN][mM];
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mMaze.resize(mN + 2, vi(mM + 2));

		char c;
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				cin >> c;
				if (c == '1')
				{
					mMaze[i][j] = 1;
				}
			}
		}
	}

	void bfs(int n0, int m0)
	{
		queue<pii> box;
		box.push({ n0, m0 });
		mMaze[n0][m0] = 1;

		int nextN, nextM;
		while (!box.empty())
		{
			auto [nowN, nowM] = box.front();
			box.pop();
			if (nowN == mN && nowM == mM)
				break;

			int nextDepth = mMaze[nowN][nowM] + 1;
			for (int i = 0; i < 4; i++)
			{
				nextN = nowN + jumpN[i];
				nextM = nowM + jumpM[i];

				if (mMaze[nextN][nextM] == 1)
				{
					mMaze[nextN][nextM] = nextDepth;
					box.push({ nextN, nextM });
				}
			}
		}
	}



private:
	vector<vi> mMaze;
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