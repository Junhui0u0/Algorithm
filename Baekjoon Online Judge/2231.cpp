//나중에 한번 봐보기
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int func(int x) {
	int sum = 0;
	int tmp = x;
	sum += x;

	while (x) {
		sum += x % 10;
		x /= 10;
	}
	if (sum == n) return tmp;
	else return 0;
}

int main() {
	cin >> n;

	for (int i = 1;i < n;i++) {
		int tmp = func(i);
		if (tmp != 0) {
			cout << tmp << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;
}