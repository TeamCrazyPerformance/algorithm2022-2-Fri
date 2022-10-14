#include <iostream>
#include <cmath>
using namespace std;

int larger(int num) {
	int nn = 0, digit = 0;
	
	do {
		if (num % 10 == 5)
			nn += 6 * pow(10, digit);
		else
			nn += num % 10 * pow(10, digit);
		digit++;
		num /= 10;
	} while (num != 0);
	
	return nn;
}

int smaller(int num) {
	int nn = 0, digit = 0;
	
	do {
		if (num % 10 == 6)
			nn += 5 * pow(10, digit);
		else
			nn += num % 10 * pow(10, digit);
		digit++;
		num /= 10;
	} while (num != 0);
	
	return nn;
}


int main() {
	int a, b;
	cin >> a >> b;
	
	cout << (smaller(a) + smaller(b)) << " " << (larger(a) + larger(b));
	
	return 0;
}