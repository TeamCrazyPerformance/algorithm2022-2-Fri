#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);
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
		priority_queue<int, vi, greater<int> > pq;	// �ּ���
		int num;
		for (int i = 0; i < mN; i++)
		{
			cin >> num;
			pq.push(num);				// ���� mN�� ��ŭ �־��ֱ�, top���� �׻� ������� ���� �� �� mN��° ū ���� ����ǰ� �� ����
		}

		for (int i = 1; i < mN; i++)
		{
			for (int j = 0; j < mN; j++)
			{
				cin >> num;
				if (pq.top() < num)		// ���ο� ���� mN��° ū ������ ũ��
				{
					pq.pop();			// ���� mN��° ū ���� mN + 1��°�� �Ǵ� pop,
					pq.push(num);		// ���ο� ���� push ���ֱ�
				}
			}
		}

		cout << pq.top();
	}


private:
	void init()
	{
		cin >> mN;
	}



private:
	int mN;

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