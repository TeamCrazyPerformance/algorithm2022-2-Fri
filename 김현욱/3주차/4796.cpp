#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int l, p, v, i = 1;
	while(true) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			return 0;
		cout << "Case " << i++ << ": " << ((v / p) * l + min(v % p, l)) << "\n";
	}
	return 0;
}