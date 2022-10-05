#include <iostream>
using namespace std;
bool has_666(int x) {
	int stack = 0;
	do
	{
		if (x % 10 == 6) stack++;
		else stack = 0;
		if (stack == 3) return true;
		x /= 10;
	} while (x > 0);
	return false;
}
int main() {
	int n; cin >> n;
	int x = 666, i = 0;
	while (1) {
		if (has_666(x) == true) i++;
		if (i == n) { cout << x; break; }
		x++;
	}
	return 0;
}
