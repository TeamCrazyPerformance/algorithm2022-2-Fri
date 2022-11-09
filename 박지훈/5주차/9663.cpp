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

		cout << mAns;
	}


private:
	void init()
	{
		cin >> mN;
		mNm1 = mN - 1;	// 계산에 반복적으로 쓰이는 값
		mAns = 0;

		mY.resize(mN);					// mY[y]이 1인 경우			-> y행에 퀸이 놓여있음
		mDia1.resize((mN << 1) - 1);	// mDia1[y + x]가 1인 경우	-> 대각선 y = -x에 퀸이 놓여있음
		mDia2.resize((mN << 1) - 1);	// mDia2[y - x]가 1인 경우	-> 대각선 y = x에 퀸이 놓여있음  (+ 배열의 idx가 음수가 나오면 안 되므로 0부터 시작하도록 mNm1을 더해줌)
	}

	void backTracking(int x)	// x열에 퀸을 놓기
	{
		if (x == mN)	// 마지막 열까지 퀸을 놓았다면 경우의 수를 +1
		{
			mAns++;
			return;
		}

		int nextX = x + 1;
		for (int y = 0; y < mN; y++)	// x열의 0행부터 차례로 퀸을 놓을 수 있는지 탐색
		{
			if (mY[y] == 0 && mDia1[y + x] == 0 && mDia2[mNm1 + y - x] == 0)	// y행, 두 대각선 방향에 퀸이 없을 경우 진입
			{
				mY[y] = mDia1[y + x] = mDia2[mNm1 + y - x] = 1;	// y행 x열에 퀸을 놓아줌

				backTracking(nextX);	// x + 1열의 퀸을 놓기 위해 진입

				mY[y] = mDia1[y + x] = mDia2[mNm1 + y - x] = 0;	// 현재 탐색이 끝났으므로 다음 탐색을 위해 퀸을 치움
			}
		}
	}


private:
	vi mY, mDia1, mDia2;
	int mN, mNm1, mAns;
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