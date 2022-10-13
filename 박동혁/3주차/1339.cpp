#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int alp[26];

bool compare(int &a, int &b)
{
    return a > b;
}

int main()
{
    int n, ans=0;
    cin >> n;
    string word[n];
    int length[n], length_max=0;
    for(int i=0; i<n; i++) {
        cin >> word[i];
        length[i]=word[i].length();
        length_max = (length[i] > length_max) ? length[i] : length_max;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<length[i]; j++) {
            alp[word[i][j]-'A'] += pow(10, length[i]-j);
        }
    }
    for(int num=9; num>=0; num--) {
        int max=0, flag=0;
        for(int i=0; i<26; i++) {
            if(alp[i]>max && alp[i]>=10) {
                max = alp[i];
                flag = i;
            }
        }
        if(max>0) 
            alp[flag] = num;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<length[i]; j++) {
            ans += alp[word[i][j]-'A'] * pow(10, length[i]-1-j);
        }
    }
    cout << ans;
}