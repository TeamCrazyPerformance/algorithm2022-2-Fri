#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
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
		bfs();

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

	void bfs()
	{
		int cnt = 1;

		queue<int> box;
		box.push(mR);			// 시작 지점 queue에 넣기
		mOrder[mR] = cnt++;		// 시작 지점 방문 기록

		while (!box.empty())
		{
			for (auto next : mEdges[box.front()])
			{
				if (mOrder[next] == 0)	// 방문하지 않았다면
				{
					mOrder[next] = cnt++;
					box.push(next);
				}
			}

			box.pop();
		}
	}


private:
	vvi mEdges;
	vi	mOrder;
	int mN, mR;
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