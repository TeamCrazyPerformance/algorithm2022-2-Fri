#include <iostream>
using namespace std;

int main() {
	int unit = 1, answer = 0, i = 1, n;
	cin >> n;
	
	while (n - unit * 10 >= 0) {
		answer += 9 * unit * (i++);
		unit *= 10;
	}
	answer += (n - unit + 1) * i;
	
	cout << answer;
	
	return 0;
}