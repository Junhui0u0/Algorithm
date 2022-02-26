#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, val, b, c;
	vector<long long> student;
	long long cnt = 0;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> val;
		student.push_back(val);
	}
	cin >> b >> c;

	for (int i = 0;i < student.size();i++) {
		student[i] -= b;
		cnt++;
	}
	for (int i = 0;i < student.size();i++) {
		if (student[i] > 0) {
			if (student[i] % c == 0) cnt += student[i] / c;
			else cnt += (student[i] / c) + 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}