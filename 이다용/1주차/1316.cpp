#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#define MAX_SIZE 100
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    string word[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        cin >> word[i];
        int sum = 0, sum_v = 0;
        for (int j = 0; j < word[i].length(); j++) {
            vector<int> v;
            int s = 0;
            for (int k = j; k < word[i].length(); k++) {
                if (word[i].at(j) == word[i].at(k)) { s++; v.push_back(k); }
            }
           
            for (int a = j; a < j + s; a++)
            {
                sum += a;
            }
            for (int b = 0; b < v.size(); b++)
            {
                sum_v += v.at(b);
            }
        }
        if (sum != sum_v) { continue; }
        count++;
    }
    cout << count;
}
