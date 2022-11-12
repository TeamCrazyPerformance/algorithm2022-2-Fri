#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

struct tri	// 행, 열, 3x3 블록의 index를 저장할 구조체
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
					mBlanks.push_back({ i, j, (i / 3) * 3 + j / 3 });		// 빈칸만 따로 기록해두는 배열 (행, 열, 3x3 index 저장)
				else
					mRow[i] |= 1 << mBoard[i][j], mCol[j] |= 1 << mBoard[i][j], mSq[(i / 3) * 3 + j / 3] |= 1 << mBoard[i][j];
			}
		}

		mN = (int)mBlanks.size();
	}

	void sdk(int idx)	// 빈칸(0)을 따로 기록해두고 순서대로 접근
	{
		if (idx == mN)
		{
			mbEnd = true;
			return;
		}

		// 현재 빈칸의 행, 열, 3x3블록 idx 가져오기
		auto [r, c, sq] = mBlanks[idx];
		// bitmask 사용, 현재 행, 열 3x3 블록의 bit들을 or 연산한 결과는 놓을 수 있는 숫자에 해당하는 bit만 0으로 남음 (1 << 9 내에서)
		int bit = (mRow[r] | mCol[c] | mSq[sq]), b;	
		for (int num = 1; num < 10; num++)
		{
			if (1 << num & bit)		// 현재 빈칸에 num을 놓을 수 없으면 다음 num으로
				continue;

			b = 1 << num;
			mRow[r] |= b;
			mCol[c] |= b;
			mSq[sq] |= b;			// 해당 행, 열, 3x3에 num을 놓았다는 표시
			mBoard[r][c] = num;

			sdk(idx + 1);			// 다음 깊이 진행
			if (mbEnd)				// 정답이 나왔을 경우 종료
				return;

			mRow[r] -= b;			
			mCol[c] -= b;
			mSq[sq] -= b;			// 탐색이 끝났으니 num을 빼주기
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