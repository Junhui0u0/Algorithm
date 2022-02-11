//대각선 방향 -> dxy[8][2]
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int arr[50][50];
bool visited[50][50] = { false, };
queue<pair<int, int>> q;
int dxy[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int cnt = 0;

void bfs(int y, int x) {
	visited[y][x] = true;
	q.push({ y,x });
	
	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int i = 0;i < 8;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (arr[ny][nx] == 1 && visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				if (arr[i][j] == 1 && visited[i][j] == false) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";

		cnt = 0;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}