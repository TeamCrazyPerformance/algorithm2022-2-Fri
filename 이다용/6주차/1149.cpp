#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int N;
vector<tuple<int, int, int>> V,C;
void init(){
	cin >> N;
	V.resize(N + 1);
	C.resize(N + 1);
	int R, G, B;
	for (int i = 1; i <= N; i++) {
		cin >> R >> G >> B;
		V[i] = { R,G,B };
	}
	C[0] = { 0,0,0 };

}

int main() {
	init();
	for (int i = 1; i <= N; i++) {
		C[i] = { get<0>(V[i]) + min(get<1>(C[i - 1]),get<2>(C[i - 1])), get<1>(V[i]) + min(get<0>(C[i - 1]),get<2>(C[i - 1])), get<2>(V[i]) + min(get<0>(C[i - 1]),get<1>(C[i - 1])) };
	}
	cout << min({ get<0>(C[N]),get<1>(C[N]),get<2>(C[N]) });
}
