#include <iostream>
#include <deque>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
typedef pair<int, int> pii;


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
		int score;		// ����� ���� ����
		cin >> score;
		mDp.push_back({ 0, 0 });
		mDp.push_back({ score, 0 });
		for (int i = 2; i <= mN; i++)
		{
			cin >> score;

			// mDp[i][0] = max(mDp[i-2][0], mDp[i-2][1] + score
			// mDp[i][1] = mDp[i-1][0] + score �� ����
			mDp.push_back({ max(mDp.front().first, mDp.front().second) + score, mDp.back().first + score });
			mDp.pop_front();	//mDp[i-2]�κ��� ���̻� �ʿ� ������ ����
		}

		cout << max(mDp.back().first, mDp.back().second);
	}


private:
	void init()
	{
		cin >> mN;
	}


private:
	deque<pii> mDp;
	int mN;

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