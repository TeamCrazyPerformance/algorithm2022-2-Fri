#include<iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt[26]={0, };
	for(int i=0; i<s.length(); i++) {
		cnt[s[i]-'a']++;
	}
	for(int i=0; i<26; i++) {
		cout << cnt[i] << ' ';
    }
    return 0;
}