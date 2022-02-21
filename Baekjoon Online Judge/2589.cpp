#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
string map[50];
int path[50][50];		//path에 거리를 저장(1씩 증가하면서)
int maxResult = 0;
bool visited[50][50] = { false, };
int dxy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int ans = 0;

int bfs(int y,int x) {
	queue<pair<int,int>> q;
	visited[y][x] = true;
	q.push({ y,x });
	path[y][x] = 0;		//

	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (map[ny][nx] == 'L'&&visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
				path[ny][nx] = path[cy][cx] + 1;
				if (maxResult < path[ny][nx]) maxResult = path[ny][nx];		//
			}
		}
	}
	return maxResult;
}

void reset() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			visited[i][j] = false;
			path[i][j] = 0;
		}
	}
	maxResult = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> map[i];
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (map[i][j] == 'L') {		//==기호 잘쓰기
				int tmp = bfs(i, j);
				ans = max(ans, tmp);
				reset();
			}
		}
	}

	cout << ans << "\n";
	return 0;
}