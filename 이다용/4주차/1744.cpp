#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> P, M;
    int N, value;
    int one = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> value;
        if (value <= 0)
            M.push_back(value);
        else if (value == 1)
            one++;
        else
            P.push_back(value);
    }
    sort(P.rbegin(), P.rend());
    sort(M.begin(), M.end());
    int result = 0;
    if (P.size() > 1) {
        for (int i = 0; i < P.size()/2; i++)
        {
            result += P[2*i] * P[2*i + 1];
        }
    }
    if (P.size() % 2 == 1)
        result += P.back();
    if (M.size() > 1) {
        for (int i = 0; i < M.size()/2; i++)
        {
            result += M[2*i] * M[2*i + 1];
        }
    }
    if (M.size() % 2 == 1)
        result += M.back();
    result += one;
    cout << result;
}
