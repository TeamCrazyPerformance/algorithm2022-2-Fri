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
		priority_queue<int> maxHeap;					// �߾Ӱ� �Ʒ�
		priority_queue<int, vi, greater<> > minHeap;	// �߾Ӱ� ��
		maxHeap.push(-10000);
		minHeap.push(10001);

		int n, x;
		cin >> n;
		while (n--)
		{
			cin >> x;
			if (x >= minHeap.top())
			{
				minHeap.push(x);
				if ((minHeap.size() - maxHeap.size()) & 2)	// 0 �ƴϸ� 2
				{
					maxHeap.push(minHeap.top());
					minHeap.pop();
				}
			}
			else
			{
				maxHeap.push(x);
				if ((maxHeap.size() - minHeap.size()) & 2)	// 0 �ƴϸ� 2
				{
					minHeap.push(maxHeap.top());
					maxHeap.pop();
				}
			}

			if (maxHeap.size() >= minHeap.size())
				cout << maxHeap.top() << "\n";
			else
				cout << minHeap.top() << "\n";
		}
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

	while (T--)
	{
		Q q;
		q.Solve();
	}

	return 0;
}