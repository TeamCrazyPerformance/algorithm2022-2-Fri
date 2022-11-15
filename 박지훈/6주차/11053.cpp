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
		// mDp[i]���� �ǹ�: �ڽ��� ���������� �ϴ� ���� �� ���� ������ ����
		for (int i = 0; i < mN; i++)			// idx�� 0������ �ϳ��� Ž��
			for (int j = i + 1; j < mN; j++)	// i���� idx�� i�� ���ں��� ũ��, �ڽ�+1�� dp���� �ش� dp���� Ŭ ��� j�� dp�� ����
				if (mNums[i] < mNums[j] && mDp[j] < mDp[i] + 1)
					mDp[j] = mDp[i] + 1;

		cout << *max_element(mDp.begin(), mDp.end());
	}


private:
	void init()
	{
		cin >> mN;
		mNums.resize(mN);
		mDp.resize(mN, 1);	// �ڱ� �ڽŵ� ���� �ϹǷ� 1�� �ʱ�ȭ

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