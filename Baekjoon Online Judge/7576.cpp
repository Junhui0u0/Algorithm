//다시풀어보기
#include <iostream>
#include <queue>
using namespace std;

int m, n;
int dxy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt = 0;
queue<pair<int, int>> q;
int arr[1000][1000];

void bfs() {
	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();
		
		for (int i = 0;i < 4;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = arr[cy][cx] + 1;
				q.push(make_pair(ny, nx));  //물들었으니깐
			}
		}
	}
}

int main() {
	cin >> m >> n;

	for (int y = 0;y < n;y++) {
		for (int x = 0;x < m;x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 0;y < n;y++) {
		for (int x = 0;x < m;x++) {
			if (arr[y][x] == 1) {
				q.push(make_pair(y, x));
			}
		}
	}

	bfs();

	for (int y = 0;y < n;y++) {
		for (int x = 0;x < m;x++) {
			if (arr[y][x] == 0) {
				cout << "-1\n";
				return 0;
			}
			if (cnt < arr[y][x]) cnt = arr[y][x];
		}
	}
	cout << cnt-1 << "\n";
	return 0;
}