#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string s_A, s_B;
	int max, min;
	cin >> s_A >> s_B;
	string temp_A = regex_replace(s_A, regex("5"), "6");
	string temp_B = regex_replace(s_B, regex("5"), "6");
	max = stoi(temp_A) + stoi(temp_B);
	temp_A = regex_replace(s_A, regex("6"), "5");
	temp_B = regex_replace(s_B, regex("6"), "5");
	min = stoi(temp_A) + stoi(temp_B);
	cout << min << " " << max;
}
