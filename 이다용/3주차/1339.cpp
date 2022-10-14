#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std; 
int  main() {
	int N;
	cin >> N;
	vector<int> V(26, 0);
	vector<char> input_v;
	for (int i = 0; i < N; i++) {
		string input_s;
		cin >> input_s;
		copy(input_s.begin(), input_s.end(),back_inserter(input_v));
		for (int j = 0; j < (int)input_v.size(); j++) {
			V[(int)input_v[j] - 65] += (int)pow(10, (int)input_v.size() - 1 - j);
		}
		input_v.clear();
	}
	sort(V.rbegin(), V.rend());
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		ans += (9 - i) * V[i];
	}
	cout << ans;
}
