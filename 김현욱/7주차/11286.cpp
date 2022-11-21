#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct compare
{
    bool operator()(int &l, int &r)
    {
        if(abs(l) == abs(r))
            return l > r;
        return abs(l) > abs(r);
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue< int, vector<int>, compare > pQ;
	int N, temp;
	
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> temp;
		if(temp == 0) {
			if(pQ.empty())
				cout << "0\n";
			else {
				cout << pQ.top() << "\n";
				pQ.pop();
			}
		} else {
			pQ.push(temp);
		}
	}
	
	return 0;
}
