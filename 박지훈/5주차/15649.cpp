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
		mSeq.resize(mM);		// 길이가 M인 수열을 담을 배열
		mCheck.resize(mN + 1);	// N개의 수 중 mSeq 배열에 들어가있는 수를 체크
	}

	void backTracking(int idx)
	{
		//	mSeq 배열에 M개의 수가 모였다면
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
				mSeq[idx] = i;		// mSeq의 현재 idx에 i를 넣어주고 i를 체크

				backTracking(next);

				mCheck[i] = 0;		// 이후의 탐색의 재귀에서 지금의 i가 쓰일 수 있어야 하므로 체크를 풀어줌
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