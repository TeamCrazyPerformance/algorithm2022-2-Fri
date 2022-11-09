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
		mTeam.resize(2);			// 팀원을 넣을 두개의 팀 배열
		mTable.resize(mN, vi(mN));	// 능력치 테이블

		for (auto& row : mTable)
			for (auto& i : row)
				cin >> i;
	}

	void backTracking(int player, int tot)	// 현재 player를 A팀, B팀에 넣는 경우로 분기, tot: 두 팀의 전력 차이 
	{
		if (player == mN)	// 마지막 선수까지 팀에 배정 되면 계산
		{
			mAns = min(mAns, abs(tot));
			return;
		}

		for (int team = 0; team < 2; team++)
		{
			if (mTeam[team].size() < mHalfN)	// 해당 팀의 크기가 N/2보다 작을 경우에 팀원을 넣어줌
			{
				int var = update(team, player);	// 현재 player가 해당 팀에 들어갈 경우 얻어지는 능력치
				mTeam[team].push_back(player);	// 현재 team에 player 넣어주기

				if (team & 1)					// 두 팀의 능력치 차이를 갱신하여 다음 깊이에 넘겨줌
					backTracking(player + 1, tot - var);
				else
					backTracking(player + 1, tot + var);

				mTeam[team].pop_back();			// 다음 탐색을 위해 현재 팀에서 player를 빼주기
			}
		}
	}

	//	해당 player가 넘겨준 team의 소속이 될 경우 생기는 능력치 반환
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