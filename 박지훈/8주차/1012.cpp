#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector<int> vi;

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
		int enterCnt = 0;

		for (int i = 0; i < mN; i++)
		{
			for (int j = 0; j < mM; j++)
			{
				if (mCropsField[i][j] == 1)
				{
					enterCnt++;		// 진입 횟수가 곧 연결 요소의 개수
					bfs(i, j);
				}
			}
		}

		cout << enterCnt << "\n";
	}


private:
	void init()
	{
		int bugNum;
		cin >> mN >> mM >> bugNum;
		mCropsField.resize(mN, vi(mM));

		int n, m;
		for (int i = 0; i < bugNum; i++)
		{
			cin >> n >> m;
			mCropsField[n][m] = 1;
		}
	}

	inline void bfs(int n0, int m0)
	{
		queue<pii> box;
		box.push({ n0, m0 });
		mCropsField[n0][m0] = 0;

		int nextN, nextM;
		while (!box.empty())
		{
			auto [nowN, nowM] = box.front();
			box.pop();

			for (int i = 0; i < 4; i++)
			{
				nextN = nowN + jumpN[i];
				nextM = nowM + jumpM[i];

				if (rangeTest(nextN, nextM) && mCropsField[nextN][nextM] == 1)
				{
					mCropsField[nextN][nextM] = 0;
					box.push({ nextN, nextM });
				}
			}
		}
	}

	inline bool rangeTest(int n, int m)
	{
		return n >= 0 && n < mN&& m >= 0 && m < mM;
	}


private:
	vector<vi> mCropsField;
	int mN, mM;
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