#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;


template<typename T>
class pq
{
public:
	pq()
	{
		mArr.push_back(0);
	}
	~pq() {}

	void Push(T element)
	{
		size_t child = mArr.size();
		mArr.push_back(element);
		while (child > 1 && cmp(mArr[child >> 1], mArr[child]))
		{
			swap(mArr[child], mArr[child >> 1]);
			child = child >> 1;
		}
	}

	void Pop()
	{
		if (Empty())
			return;

		mArr[1] = mArr.back();
		mArr.pop_back();

		size_t parent = 1;
		while ((parent << 1) < mArr.size())
		{
			if (cmp(mArr[parent], mArr[parent << 1]))
			{
				if (cmp(mArr[parent << 1], mArr[(parent << 1) | 1]))
				{
					swap(mArr[parent], mArr[(parent << 1) | 1]);
					parent = (parent << 1) | 1;
				}
				else
				{
					swap(mArr[parent], mArr[parent << 1]);
					parent = parent << 1;
				}
			}
			else if (((parent << 1) | 1) < mArr.size() && cmp(mArr[parent], mArr[(parent << 1) | 1]))
			{
				swap(mArr[parent], mArr[(parent << 1) | 1]);
				parent = (parent << 1) | 1;
			}
			else
				break;
		}
	}

	T Top()
	{
		if (Empty())
			return 0;	// error

		return mArr[1];
	}

	bool Empty()
	{
		return mArr.size() == 1;
	}

private:
	bool cmp(T& child, T& parent)
	{
		return child > parent;		// ÃÖ¼Ò Èü
	}

private:
	vector<T> mArr;
};




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
		int queryNum, q;
		cin >> queryNum;
		while (queryNum--)
		{
			cin >> q;
			if (q > 0)
				mPq.Push(q);
			else
			{
				cout << mPq.Top() << "\n";
				mPq.Pop();
			}
		}
	}


private:
	void init()
	{

	}


private:
	pq<int> mPq;
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