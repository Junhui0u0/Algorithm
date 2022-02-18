#include <iostream>
#include <vector>
using namespace std;

int n, t, p;
vector<pair<int, int>> v;
int maxResult = 0;

void func(int idx, int result) {
	if (result > maxResult) maxResult = result;

	for(int i=idx;i<n;i++){
		if (i + v[i].first <= n) {
			result += v[i].second;
			func(i + v[i].first, result);
			result -= v[i].second;
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> t >> p;
		v.push_back({ t,p });
	}

	func(0, 0);
	cout << maxResult << "\n";
	return 0;
}