//Greedy Algorithm
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string arr[10];
int alpha[26];
int num = 9;
int ans = 0;

void func() {
	for (int i = 0;i < n;i++) {
		int pow = 1;	//ÀÚ¸´¼ö
		for (int j = arr[i].size() - 1;j >= 0;j--) {
			int val = arr[i][j] - 'A';
			alpha[val] += pow;
			pow *= 10;
		}
	}
	sort(alpha, alpha + 26);
	for (int i = 25;i >= 0;i--) {
		if (alpha[i] == 0) break;
		ans += alpha[i] * num;
		num--;
	}
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	func();
	cout << ans << "\n";
	return 0;
}