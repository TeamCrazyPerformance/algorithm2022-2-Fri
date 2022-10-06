#include <iostream>
using namespace std;
int main() {
	int N; cin >> N; int Han;
	if (N <= 99) { Han = N; }
	else {
		Han = 99;
		for (int i = 100; i <= N; i++) {
			int temp = i; int diff_A = (i % 100) / 10 - i % 10;
			bool endflag = false;
			do {
				int diff = (temp % 100) / 10 - temp % 10;
				if (diff != diff_A) { endflag = true; break; }
				temp /= 10;
			} while (temp >= 10);
			if (endflag==true) { continue; }
			Han++;
		}
	}
	cout << Han;
}
