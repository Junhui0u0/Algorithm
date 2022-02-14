//'한수'구하기
#include <iostream>
using namespace std;

bool func(int x) {	//한수구하기
	if (x < 100) return true;

	int x1, x2, x3;
	x3 = x / 100;
	x1 = x % 10;
	x2 = x % 100 / 10;

	if (x3 - x2 == x2 - x1) return true;
	else return false;
}

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		if (func(i) == true) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}