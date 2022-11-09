#include <iostream>
using namespace std;

int n, m;
bool visited[9] = {}; 
int arr[9] = {}; 

void recursive(int k){
	if(m == k){
		for(int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			visited[i] = true;
			arr[k] = i;
            recursive(k+1);
            visited[i] = false;
        }
    }
}

int main() {
	cin >> n >> m;
	
	recursive(0);
	
	return 0;
}