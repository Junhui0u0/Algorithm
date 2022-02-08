//dfs
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
int arr[25][25];
bool visited[25][25] = { false, };
int houseSize = 0;
vector<int> houseCnt;
int dxy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void dfs(int y, int x) {
	visited[y][x] = true;
	houseSize++;

	for (int i = 0;i < 4;i++) {
		int next_x = x + dxy[i][1];
		int next_y = y + dxy[i][0];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
			continue;
		if (arr[next_y][next_x] == 1 && visited[next_y][next_x] == false) {
			dfs(next_y, next_x);
		}
	}
}


int main() {
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> s;
		for (int j = 0;j < n;j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				dfs(i, j);
				houseCnt.push_back(houseSize);
				houseSize = 0;
			}
		}
	}

	cout << houseCnt.size() << "\n";
	sort(houseCnt.begin(), houseCnt.end());
	for (int i = 0;i < houseCnt.size();i++) {
		cout << houseCnt[i] << "\n";
	}
	return 0;
}