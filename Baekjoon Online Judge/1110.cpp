#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;
	int startNum = 0;
	string s;
	cin >> s;
	startNum = stoi(s);
	while (true) {
		cnt++;
		int rightVal, rightSumVal = 0;
		rightVal = s[s.size() - 1] - '0';
		int sum = 0;
		for (int i = 0;i < s.size();i++) {
			sum += s[i] - '0';
		}

		string sumstr = to_string(sum);
		rightSumVal = sumstr[sumstr.size() - 1] - '0';

		string result;
		result += to_string(rightVal);
		result += to_string(rightSumVal);

		int tmp = stoi(result);
		if (tmp == startNum) break;
		else s = result;
	}
	cout << cnt << "\n";
	return 0;
}