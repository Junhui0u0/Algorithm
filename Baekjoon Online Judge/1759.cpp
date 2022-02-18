#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
char arr[13];
char alphabet;
vector<char> v;
int vowelCnt = 0;	//모음
int consonantCnt = 0;	//자음
vector<string> sv;

bool IsVowel(char s) {
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
		return true;
	}
	else return false;
}

void print() {
	string s = "";
	vector<char> tmp = v;
	sort(tmp.begin(), tmp.end());
	for (int i = 0;i < tmp.size();i++) {
		s += tmp[i];
	}
	sv.push_back(s);
}

void func(int idx) {
	if (vowelCnt + consonantCnt == l) {
		if (vowelCnt < 1) return;
		if (consonantCnt < 2) return;
		print();		//point
	}

	for (int i = idx;i < c;i++) {		//point
		if (IsVowel(arr[i])) vowelCnt++;
		else consonantCnt++;
		v.push_back(arr[i]);

		func(i + 1);

		if (IsVowel(arr[i])) vowelCnt--;
		else consonantCnt--;
		v.pop_back();
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0;i < c;i++) {
		cin >> arr[i];
	}
	func(0);
	sort(sv.begin(), sv.end());
	for (int i = 0;i < sv.size();i++) {
		cout << sv[i] << "\n";
	}
	return 0;
}