#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << min(4, (m + 1) / 2);
	else if (n >= 3) {
		if (m <= 6)
			cout << min(4, m) << endl;
		else
			cout << m - 2 << endl;
	}
	return 0;
}