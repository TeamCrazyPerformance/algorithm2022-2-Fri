#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;


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
		int n,						// ���� ����
			prevR, prevG, prevB,	// �ش� ������ ĥ�� ���� ���� �ּҺ��
			r, g, b;				// ���� ���� ��ĥ ���

		cin >> n >> prevR >> prevG >> prevB;
		while (--n)
		{
			cin >> r >> g >> b;
			r += (prevG < prevB ? prevG : prevB);
			g += (prevR < prevB ? prevR : prevB);
			b += (prevR < prevG ? prevR : prevG);	// �ڽŰ� �ٸ� ������ ĥ�� ���� ���� �ּҸ� ���� ��뿡 ������
			prevR = r;
			prevG = g;
			prevB = b;		// ���� Ž���� ���� ���� �ּ� ����� ���� ���� ������� ����
		}

		cout << min(r, min(g, b));
	}


private:
	void init()
	{
	}


private:

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