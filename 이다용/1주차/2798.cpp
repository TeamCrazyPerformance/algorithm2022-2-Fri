#include <iostream>
#define MAX_SIZE 101
using namespace std;

int main() {
    int N, M,arr[MAX_SIZE],Nst=0,sum=0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= N - 2; i++){
        for (int j = i+1;  j <= N - 1; j++){
            for (int k = j+1; k <= N; k++){
                sum = arr[i] + arr[j] + arr[k];
                if (sum > Nst && sum <= M)
                    Nst = sum;
            }
        }
        if (Nst == M)
            break;
    }
    cout << Nst;

}
