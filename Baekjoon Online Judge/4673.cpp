#include <iostream>
using namespace std;

bool arr[10001] = { false, };

void func(int x) {
	int sum = 0;
	sum += x;

	while (x) {		//각 자릿수의 합
		sum += x % 10;
		x /= 10;
	}
	arr[sum] = true;
}

int main() {
	for (int i = 1;i <= 10000;i++) {
		func(i);
		if (arr[i] == false) {
			cout << i << "\n";
		}
	}

	return 0;
}