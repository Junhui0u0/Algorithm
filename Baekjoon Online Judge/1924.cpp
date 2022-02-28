#include <iostream>
#include <string>
using namespace std;

int main() {
	string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int totalDate[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int ans = 0;

	int x, y;
	cin >> x >> y;
	for (int i = 1;i <= x;i++) {
		ans += totalDate[i - 1];
	}
	ans += y - 1;

	cout << day[ans % 7] << "\n";
	return 0;
}