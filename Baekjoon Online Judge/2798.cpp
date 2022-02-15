//조합(순열)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num;
vector<int> v;
int maxSum = 0;

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				if (v[i] != v[j] && v[i] != v[k] && v[j] != v[k]) {
					int sum = v[i] + v[j] + v[k];
					if (sum <= m) maxSum = max(maxSum, sum);
				}
			}
		}
	}

	cout << maxSum << "\n";

	return 0;
}