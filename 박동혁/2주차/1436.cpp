#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 666;
	for(int cnt=0; cnt!=n; num++) {
		int tmp = num;
		while(tmp>=666){
			if(tmp%1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		}
	}
	cout << num-1;
}