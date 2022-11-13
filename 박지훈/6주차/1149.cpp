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
		int n,						// 집의 개수
			prevR, prevG, prevB,	// 해당 색으로 칠한 이전 집의 최소비용
			r, g, b;				// 현재 집의 색칠 비용

		cin >> n >> prevR >> prevG >> prevB;
		while (--n)
		{
			cin >> r >> g >> b;
			r += (prevG < prevB ? prevG : prevB);
			g += (prevR < prevB ? prevR : prevB);
			b += (prevR < prevG ? prevR : prevG);	// 자신과 다른 색으로 칠한 이전 집의 최소를 현재 비용에 더해줌
			prevR = r;
			prevG = g;
			prevB = b;		// 다음 탐색을 위해 현재 최소 비용을 이전 집의 비용으로 대입
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