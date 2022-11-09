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
		mNm1 = mN - 1;	// ��꿡 �ݺ������� ���̴� ��
		mAns = 0;

		mY.resize(mN);					// mY[y]�� 1�� ���			-> y�࿡ ���� ��������
		mDia1.resize((mN << 1) - 1);	// mDia1[y + x]�� 1�� ���	-> �밢�� y = -x�� ���� ��������
		mDia2.resize((mN << 1) - 1);	// mDia2[y - x]�� 1�� ���	-> �밢�� y = x�� ���� ��������  (+ �迭�� idx�� ������ ������ �� �ǹǷ� 0���� �����ϵ��� mNm1�� ������)
	}

	void backTracking(int x)	// x���� ���� ����
	{
		if (x == mN)	// ������ ������ ���� ���Ҵٸ� ����� ���� +1
		{
			mAns++;
			return;
		}

		int nextX = x + 1;
		for (int y = 0; y < mN; y++)	// x���� 0����� ���ʷ� ���� ���� �� �ִ��� Ž��
		{
			if (mY[y] == 0 && mDia1[y + x] == 0 && mDia2[mNm1 + y - x] == 0)	// y��, �� �밢�� ���⿡ ���� ���� ��� ����
			{
				mY[y] = mDia1[y + x] = mDia2[mNm1 + y - x] = 1;	// y�� x���� ���� ������

				backTracking(nextX);	// x + 1���� ���� ���� ���� ����

				mY[y] = mDia1[y + x] = mDia2[mNm1 + y - x] = 0;	// ���� Ž���� �������Ƿ� ���� Ž���� ���� ���� ġ��
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