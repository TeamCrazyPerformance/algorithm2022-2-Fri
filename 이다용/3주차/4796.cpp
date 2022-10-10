#include <iostream>
using namespace std;

int main() {
	int L, P, V, D;
	int i = 1;
	while(1){
		D = 0;
		cin >> L >> P >> V;
		if (V == 0 && P == 0 && L == 0) return 0;
		if(V%P>L) D = V / P * L + L;
		else D = V / P * L + V % P;
		cout << "Case " << i << ": " << D << "\n";
		i++;
	}
}
