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
		//	mSeq �迭�� M���� ���� �𿴴ٸ�
		if (idx >= mM)
		{
			cout << mSeq;
			return;
		}

		int next = idx + 2;
		for (int i = 1; i <= mN; i++)
		{
			mSeq[idx] = char(i + 48);		// mSeq�� ���� idx�� i�� �־��ֱ�(char Type����)

			backTracking(next);	// ���� ���� Ž��
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