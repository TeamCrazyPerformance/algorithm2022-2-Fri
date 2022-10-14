#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> word;
	int n, counter[26] = {}, last = 9, result = 0;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		word.push_back(str);
	}
	
	for (int i = 0; i < word.size(); i++) {
		int digit = 1;
		for (int j = word[i].size() - 1; j >= 0; j--) {
			char c = word[i].at(j) - 'A';
			counter[c] += digit;
			digit *= 10;
		}
	}
	
	sort(counter, counter + 26);
	
	for (int i = 25; i >= 0; i--) {
		if (counter[i] == 0)
			break;
		result += (counter[i] * last);
		last--;
	}
	
	cout << result;
	
	return 0;
}