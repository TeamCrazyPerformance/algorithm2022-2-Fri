#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

struct tri	// ��, ��, 3x3 ����� index�� ������ ����ü
{
	int r, c, sq;
};

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
		sdk(0);

		for (auto& row : mBoard)
		{
			for (auto i : row)
				cout << i << " ";
			cout << "\n";
		}
	}


private:
	void init()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> mBoard[i][j];
				if (mBoard[i][j] == 0)
					mBlanks.push_back({ i, j, (i / 3) * 3 + j / 3 });		// ��ĭ�� ���� ����صδ� �迭 (��, ��, 3x3 index ����)
				else
					mRow[i] |= 1 << mBoard[i][j], mCol[j] |= 1 << mBoard[i][j], mSq[(i / 3) * 3 + j / 3] |= 1 << mBoard[i][j];
			}
		}

		mN = (int)mBlanks.size();
	}

	void sdk(int idx)	// ��ĭ(0)�� ���� ����صΰ� ������� ����
	{
		if (idx == mN)
		{
			mbEnd = true;
			return;
		}

		// ���� ��ĭ�� ��, ��, 3x3��� idx ��������
		auto [r, c, sq] = mBlanks[idx];
		// bitmask ���, ���� ��, �� 3x3 ����� bit���� or ������ ����� ���� �� �ִ� ���ڿ� �ش��ϴ� bit�� 0���� ���� (1 << 9 ������)
		int bit = (mRow[r] | mCol[c] | mSq[sq]), b;	
		for (int num = 1; num < 10; num++)
		{
			if (1 << num & bit)		// ���� ��ĭ�� num�� ���� �� ������ ���� num����
				continue;

			b = 1 << num;
			mRow[r] |= b;
			mCol[c] |= b;
			mSq[sq] |= b;			// �ش� ��, ��, 3x3�� num�� ���Ҵٴ� ǥ��
			mBoard[r][c] = num;

			sdk(idx + 1);			// ���� ���� ����
			if (mbEnd)				// ������ ������ ��� ����
				return;

			mRow[r] -= b;			
			mCol[c] -= b;
			mSq[sq] -= b;			// Ž���� �������� num�� ���ֱ�
		}
	}


private:
	vector<tri> mBlanks;
	int mBoard[9][9];
	int mRow[9]{}, mCol[9]{}, mSq[9]{};
	int mN;
	bool mbEnd = false;
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