#include<iostream>

using namespace std;

int main()
{
    int n, m, min=64;
    cin >> n >> m;
    string chess_bw[8] = {
        "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB",
        "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"
    };
    string chess_wb[8] = {
        "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW",
        "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"
    };
    char board[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n-7; i++) {
        for(int j=0; j<m-7; j++) {
            int fix_wb=0, fix_bw=0;
            for(int row=i; row<i+8; row++) {
                for(int column=j; column<j+8; column++) {
                    if(board[row][column]!=chess_wb[row-i][column-j]) {
                        fix_wb++;
                    }
                    if(board[row][column]!=chess_bw[row-i][column-j]) {
                        fix_bw++;
                    }
                }
            }
            int tmp = (fix_wb < fix_bw) ? fix_wb : fix_bw;
            min = (tmp < min) ? tmp : min;
        }
    }
    cout << min;

    return 0;
}