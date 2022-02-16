//다시 풀어보기
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

		/* 숫자 안에 666이 있는지 체크*/
		do {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		} while (tmp > 0);

		/*n번째 숫자를 찾으면 출력*/
		if (cnt == n) {
			cout << start << "\n";
			break;
		}

		start++;
	}
	return 0;
}