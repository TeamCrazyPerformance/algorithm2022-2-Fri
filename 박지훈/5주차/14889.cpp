#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


class Q
{
public:
	Q()
	{
		init();
	}

	void Solve()
	{
		backTracking(0, 0);

		cout << mAns;
	}


private:
	void init()
	{
		cin >> mN;
		mHalfN = mN >> 1;
		mTeam.resize(2);			// ������ ���� �ΰ��� �� �迭
		mTable.resize(mN, vi(mN));	// �ɷ�ġ ���̺�

		for (auto& row : mTable)
			for (auto& i : row)
				cin >> i;
	}

	void backTracking(int player, int tot)	// ���� player�� A��, B���� �ִ� ���� �б�, tot: �� ���� ���� ���� 
	{
		if (player == mN)	// ������ �������� ���� ���� �Ǹ� ���
		{
			mAns = min(mAns, abs(tot));
			return;
		}

		for (int team = 0; team < 2; team++)
		{
			if (mTeam[team].size() < mHalfN)	// �ش� ���� ũ�Ⱑ N/2���� ���� ��쿡 ������ �־���
			{
				int var = update(team, player);	// ���� player�� �ش� ���� �� ��� ������� �ɷ�ġ
				mTeam[team].push_back(player);	// ���� team�� player �־��ֱ�

				if (team & 1)					// �� ���� �ɷ�ġ ���̸� �����Ͽ� ���� ���̿� �Ѱ���
					backTracking(player + 1, tot - var);
				else
					backTracking(player + 1, tot + var);

				mTeam[team].pop_back();			// ���� Ž���� ���� ���� ������ player�� ���ֱ�
			}
		}
	}

	//	�ش� player�� �Ѱ��� team�� �Ҽ��� �� ��� ����� �ɷ�ġ ��ȯ
	inline int update(int team, int player)
	{
		int tot = 0;
		for (auto member : mTeam[team])
			tot += mTable[player][member] + mTable[member][player];

		return tot;
	}


private:
	vvi mTable, mTeam;
	int mN, mHalfN, mAns = 0x7FFFFFFF;
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