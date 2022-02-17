#include <iostream>
using namespace std;

int n;
int num[11];
int operators[4];
int maxResult = -1000000001;
int minResult = 1000000001;

void func(int result, int idx) {
	if (idx == n) {
		if (result > maxResult) maxResult = result;
		if (result < minResult) minResult = result;
		return;
	}
	for (int i = 0;i < 4;i++) {
		if (operators[i] > 0) {
			operators[i]--;
			if (i == 0)
				func(result + num[idx], idx + 1);
			else if (i == 1)
				func(result - num[idx], idx + 1);
			else if (i == 2)
				func(result * num[idx], idx + 1);
			else
				func(result / num[idx], idx + 1);
			operators[i]++;
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num[i];
	}
	for (int i = 0;i < 4;i++) {
		cin >> operators[i];
	}

	func(num[0], 1);
	cout << maxResult << "\n";
	cout << minResult << "\n";
	return 0;
}