#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int sum = 0, s = i;
		do{
			sum += s % 10;
			s = s/10;
		}while (s != 0);
		if (N == i + sum) { cout << i; return 0; }
	}
	cout << "0";
	return 0;
}
