#include <iostream>
using namespace std;

int n, m;
int arr[9] = {}; 

void recursive(int k){
	if(m == k){
		for(int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 1; i <= n; i++){
		arr[k] = i;
        recursive(k+1);
    }
}

int main() {
	cin >> n >> m;
	
	recursive(0);
	
	return 0;
}
