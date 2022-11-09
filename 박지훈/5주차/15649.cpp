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
	}


private:
	void init()
	{
		cin >> mN >> mM;
		mSeq.resize(mM);		// ���̰� M�� ������ ���� �迭
		mCheck.resize(mN + 1);	// N���� �� �� mSeq �迭�� ���ִ� ���� üũ
	}

	void backTracking(int idx)
	{
		//	mSeq �迭�� M���� ���� �𿴴ٸ�
		if (idx == mM)
		{
			for (int num : mSeq)
				cout << num << " ";
			cout << "\n";
			return;
		}

		int next = idx + 1;
		for (int i = 1; i <= mN; i++)
		{
			if (mCheck[i] == 0)
			{
				mCheck[i] = 1;		
				mSeq[idx] = i;		// mSeq�� ���� idx�� i�� �־��ְ� i�� üũ

				backTracking(next);

				mCheck[i] = 0;		// ������ Ž���� ��Ϳ��� ������ i�� ���� �� �־�� �ϹǷ� üũ�� Ǯ����
			}
		}
	}



private:
	vi mSeq, mCheck;
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