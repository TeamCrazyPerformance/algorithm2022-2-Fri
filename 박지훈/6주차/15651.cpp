#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;


class Q
{
public:
	Q()
	{
		init();
	}

	~Q()
	{
		free(mSeq);
	}

	void Solve()
	{
		backTracking(0);
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mM <<= 1;
		mSeq = (char*)malloc(sizeof(char) * (mM + 1));

		for (int i = 1; i < mM; i += 2)
			mSeq[i] = ' ';
		mSeq[mM - 1] = '\n';
		mSeq[mM] = '\0';
	}

	void backTracking(int idx)
	{
		//	mSeq 배열에 M개의 수가 모였다면
		if (idx >= mM)
		{
			cout << mSeq;
			return;
		}

		int next = idx + 2;
		for (int i = 1; i <= mN; i++)
		{
			mSeq[idx] = char(i + 48);		// mSeq의 현재 idx에 i를 넣어주기(char Type으로)

			backTracking(next);	// 다음 깊이 탐색
		}
	}


private:
	char* mSeq;
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