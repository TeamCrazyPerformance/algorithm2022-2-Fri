#include <iostream>
using namespace std;

int main() {
	int n, oddSum = 0, oddMin = 100;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 != 0) {
			oddSum += n;
			if (n < oddMin) {
				oddMin = n;
			}
		}
	}
	if (oddSum == 0) {
		cout << -1;
	} else {
		cout << oddSum << '\n' << oddMin;
	}

	return 0;
}
