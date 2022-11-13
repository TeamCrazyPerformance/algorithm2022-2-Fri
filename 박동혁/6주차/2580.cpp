#include<iostream>
#include<vector>

using namespace std;

int sudoku[10][10];
vector<pair <int, int> > blank;
bool complete;
bool check(int x, int y)
{
    for(int i=1; i<=9; i++) {
        if(sudoku[x][i] == sudoku[x][y] && i!=y) return false;
        if(sudoku[i][y] == sudoku[x][y] && i!=x) return false;
    }
    for(int i=(x-1)/3 *3+1; i<=(x-1)/3 *3+3; i++) {
        for(int j=(y-1)/3 *3+1; j<=(y-1)/3 *3+3; j++) {
            if(sudoku[i][j] == sudoku[x][y] && i!=x && j!=y) return false;
        }
    }
    return true;
}

void recur(int k)
{
    if(complete)
        return;
    if(k == blank.size()) {
        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        complete = true;
        return;
    }

    int x = blank[k].first, y = blank[k].second;
    for(int i=1; i<=9; i++) {
        sudoku[x][y] = i;
        if(check(x, y)) recur(k+1);
    }
    sudoku[x][y]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            cin >> sudoku[i][j];
            if(sudoku[i][j]==0)
                blank.push_back(make_pair(i, j));
        }
    }

    recur(0);
}