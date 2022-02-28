/*변수 초기화 중요!*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string word[101];

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> word[i];
	}
	for (int i = 0;i < n;i++) {
		bool alpha[27];
		bool check = true;
		memset(alpha, false, sizeof(alpha));		//초기화
		for (int j = 0;j < word[i].length();j++) {
			if (j > 0) {
				if (alpha[word[i][j] - 'a'] == true && word[i][j] != word[i][j - 1])check = false;
			}
			alpha[word[i][j] - 'a'] = true;
			if (check == false) {
				break;
			}
		}
		if (check == true) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}