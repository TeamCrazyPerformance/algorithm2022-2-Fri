#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 2147483647;
bool visited[20] = {};
int S[20][20];

void recursive(int k, int l){
	if(N / 2 == k){
		int sts = 0, lts = 0, temp;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(i != j && visited[i] == visited[j]) {
					if(visited[i] == 1)
						sts += S[i][j];
					else
						lts += S[i][j];
				}
			}
		}
		
		temp = sts - lts;
		if(temp < 0) temp *= -1;
		answer = min(answer, temp);
		
		return;
	}
	
	for(int i = l; i < N; i++){
		if(!visited[i]){
			visited[i] = true;
            recursive(k + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> N;
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	
	recursive(0, 0);
	
	cout << answer;
	
	return 0;
}
