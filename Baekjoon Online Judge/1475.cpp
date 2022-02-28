#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, cnt = 0;
	int numCnt[10] = { 0,0,0,0,0,0,0,0,0,0 };
	cin >> n;

	string s = to_string(n);
	for (int i = 0;i < s.size();i++) {
		numCnt[s[i] - '0']++;
	}

	int tmp = numCnt[6] + numCnt[9];
	if (tmp % 2 == 0) {
		numCnt[6] = tmp / 2;
		numCnt[9] = tmp / 2;
	}
	else {
		numCnt[6] = (tmp / 2) + 1;
		numCnt[9] = (tmp / 2) + 1;
	}

	sort(numCnt, numCnt + 10, greater<int>());
	cout << numCnt[0] << "\n";
	return 0;
}