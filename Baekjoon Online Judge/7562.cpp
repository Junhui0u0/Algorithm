//다시 풀어보기
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a, b, c, d;
int arr[300][300] = { 0, };
bool visited[300][300] = { false, };
int cnt = 0;
int dxy[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
int controll = 0;

void bfs(int b, int a, int d, int c) {
	queue<pair<int, int>> q;
	q.push({ b,a });
	visited[b][a] = true;
	arr[b][a] = 0;

	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int i = 0;i < 8;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[ny][nx] == false) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
				arr[ny][nx] = arr[cy][cx] + 1;
			}
			if (ny == d && nx == c) {
				cout << arr[ny][nx] << "\n";
				return;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a >> b;
		cin >> c >> d;
		bfs(b, a, d, c);
		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}