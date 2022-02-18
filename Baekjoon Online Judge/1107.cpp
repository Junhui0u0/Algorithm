//다시 풀어보기
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n, m, num;
int arr;
bool isBroken[10] = { false, };

bool check(int x) {
	string s = to_string(x);
	for (int i = 0;i < s.length();i++) {
		if (isBroken[s[i] - '0']) return false;
	}
	return true;
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> num;
		isBroken[num] = true;
	}

	int minimum = abs(n - 100);
	for (int i = 0;i <= 1000000;i++) {
		if (check(i)) {
			int tmp = abs(n - i) + to_string(i).length();
			minimum = min(minimum, tmp);
		}
	}
	cout << minimum << "\n";
	return 0;
}