#include <iostream>
#include <vector>
using namespace std;

int n, x, y;
vector<pair<int,int>> v;

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}

	int rank = 1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i].first < v[j].first&&v[i].second < v[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
		rank = 1;
	}
	return 0;
}