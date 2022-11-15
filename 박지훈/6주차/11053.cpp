#include <iostream>
#include <vector>
#include <algorithm>
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

	~Q() {}

	void Solve()
	{
		// mDp[i]값의 의미: 자신을 마지막으로 하는 가장 긴 증가 수열의 길이
		for (int i = 0; i < mN; i++)			// idx의 0번부터 하나씩 탐색
			for (int j = i + 1; j < mN; j++)	// i뒤의 idx중 i의 숫자보다 크고, 자신+1의 dp값이 해당 dp보다 클 경우 j의 dp를 갱신
				if (mNums[i] < mNums[j] && mDp[j] < mDp[i] + 1)
					mDp[j] = mDp[i] + 1;

		cout << *max_element(mDp.begin(), mDp.end());
	}


private:
	void init()
	{
		cin >> mN;
		mNums.resize(mN);
		mDp.resize(mN, 1);	// 자기 자신도 포함 하므로 1로 초기화

		for (auto& num : mNums)
			cin >> num;
	}



private:
	vi mNums, mDp;
	int mN;

};


int main()
{
	fastio;

	int T;
	T = 1;
	//cin >> T;
	//time_t start = clock();

	while (T--)
	{
		Q q;
		q.Solve();
	}

	//cout << "\n" << ld(clock() - start)/CLOCKS_PER_SEC;

	return 0;
}