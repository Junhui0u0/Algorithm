//�ٽ� Ǯ���
#include <iostream>
using namespace std;

int cnt = 0;

int main() {
	int start = 666;
	int tmp = 0;
	int n;
	cin >> n;

	while (true) {
		tmp = start;

		/* ���� �ȿ� 666�� �ִ��� üũ*/
		do {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		} while (tmp > 0);

		/*n��° ���ڸ� ã���� ���*/
		if (cnt == n) {
			cout << start << "\n";
			break;
		}

		start++;
	}
	return 0;
}