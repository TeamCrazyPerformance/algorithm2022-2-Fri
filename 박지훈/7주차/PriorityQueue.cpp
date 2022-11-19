#include <iostream>
#include <vector>
#include <algorithm>

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