#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string wb[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};

string bw[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};

string arr[50];

int wbCnt(int x, int y) {
	int cnt = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (arr[x + i][y + j] != wb[i][j])
				cnt++;
		}
	}
	return cnt;
}

int bwCnt(int x, int y) {
	int cnt = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (arr[x + i][y + j] != bw[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main() {
	int n, m;
	int minCnt = 100000;
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	for (int i = 0;i + 8 <= n;i++) {
		for (int j = 0;j + 8 <= m;j++) {
			int tmp = 0;
			tmp = min(wbCnt(i, j), bwCnt(i, j));
			if (tmp < minCnt)minCnt = tmp;
		}
	}
	cout << minCnt << "\n";
	return 0;
}