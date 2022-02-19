#include <iostream>
using namespace std;

int n, s;
int arr[20];
int cnt = 0;
int a = 0;

void func(int idx, int result) {
	for (int i = idx;i < n;i++) {
		result += arr[i];
		func(i + 1, result);
		if (result == s) cnt++;		//point
		result -= arr[i];
	}
	return;
}

int main() {
	cin >> n >> s;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	func(0, 0);
	cout << cnt << "\n";
	return 0;
}