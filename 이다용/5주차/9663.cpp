#include<iostream>
#include<vector>
using namespace std;
int Count = 0;
typedef vector<int> vi;
int Nm1; int N;
vi mY, mDia1, mDia2;
void init() {
	cin >> N;
	Nm1 = N - 1;
	mY.resize(N);
	mDia1.resize((N << 1) - 1);
	mDia2.resize((N << 1) - 1); //1비트 이동후 -1;
}
void backTracking(int x)
{
	if (x == N) {
		Count++;
		return;
	}
	int nextX = x + 1;
	for (int y = 0; y < N; y++) {
		if (mY[y] == 0 && mDia1[y + x] == 0 && mDia2[Nm1 + y - x] == 0)
		{
			mY[y] = mDia1[y + x] = mDia2[Nm1 + y - x] = 1;
			backTracking(nextX);
			mY[y] = mDia1[y + x] = mDia2[Nm1 + y - x] = 0;
		}
	}
}
int main() {

	init();
	backTracking(0);
	cout << Count;
}
