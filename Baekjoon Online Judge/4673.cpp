#include <iostream>
using namespace std;

bool arr[10001] = { false, };

void func(int x) {
	int sum = 0;
	sum += x;

	while (x) {		//�� �ڸ����� ��
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