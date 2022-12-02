#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef pair<int, int> pii;
typedef vector<int> vi;


int jumpN[4] = { 0,0,-1,1 };
int jumpM[4] = { -1,1,0,0 };


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
		int max;
		max = bfs();

		cout << max;
	}


private:
	void init()
	{
		cin >> mM >> mN;
		mContainer.resize(mN + 2, vi(mM + 2, -1));	// 길이 2 추가와 -1로 초기화를 이용해 범위 체크를 생략
		for (int i = 1; i <= mN; i++)
		{
			for (int j = 1; j <= mM; j++)
			{
				std::cin >> mContainer[i][j];
				if (mContainer[i][j] == 1)			// 익은 토마토들 queue에 미리 담아두기
					mBox.push({ i,j });
			}
		}


	}

	int bfs()
	{
		int nextN, nextM, nextDepth;
		while (!mBox.empty())
		{
			auto [nowN, nowM] = mBox.front();
			mBox.pop();

			nextDepth = mContainer[nowN][nowM] + 1;
			for (int i = 0; i < 4; i++)
			{
				nextN = nowN + jumpN[i];
				nextM = nowM + jumpM[i];

				if (mContainer[nextN][nextM] == 0)
				{
					mContainer[nextN][nextM] = nextDepth;
					mBox.push({ nextN, nextM });
				}
			}
		}

		int ret_max = 0;
		for (auto& row : mContainer)
		{
			for (auto& i : row)
			{
				if (i == 0)
					return -1;

				ret_max = max(ret_max, i);
			}
		}

		return ret_max - 1;
	}



private:
	queue<pii> mBox;
	vector<vi> mContainer;
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