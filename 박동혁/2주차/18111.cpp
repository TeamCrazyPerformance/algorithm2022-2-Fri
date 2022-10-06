#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, b, highest=0;
    cin >> n >> m >> b;
    int block[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> block[i][j];
            highest = (block[i][j] > highest) ? block[i][j] : highest;
        }
    }
    int time_min = 2000000000, height_max=0;
    for(int height=0; height<=256; height++) {
        int time = 0, tmp_b = b;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(block[i][j]>height) {
                    time += (block[i][j]-height)*2;
                    tmp_b += block[i][j]-height;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(block[i][j]<height && tmp_b>=0) {
                    time += height-block[i][j];
                    tmp_b -= height-block[i][j];
                }
                if(tmp_b<0) {
                    break;
                }
            }
        }
        if(tmp_b>=0) {
            if(time <= time_min) {
                time_min = time;
                height_max = height;
            }
        }
    }
    cout << time_min << ' ' << height_max;
}