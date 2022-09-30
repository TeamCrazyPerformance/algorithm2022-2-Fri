#include <iostream>
#include <string>
using namespace std;

int main() {
	int alpha[26] = {}; //배열 생성
	string str; 
	cin >> str; //값입력받기
	for (int i = 0; i < str.length(); i++) { //str길이만큼 for문 작동
		int temp = str[i] - 97;  //아스키 코드 a가 97이라서 빼줌
		alpha[temp] += 1;     //개수 더해주기
	}
	for (int i = 0; i < 26; i++) {  //알파벳 숫자 26개 만큼 for 문 작동
		cout << alpha[i] << " ";
	}
	return 0;
}
