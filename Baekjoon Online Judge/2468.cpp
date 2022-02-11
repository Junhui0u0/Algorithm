//마지막 예외처리 (문제 잘 읽기->문제 괄호부분) 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
bool depth[101] = { false, };
int mapCopy[100][100];
int map[100][100];
vector<int> v;
int dxy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visited[100][100] = { false, };
int cnt = 0;
vector<int> cntVector;

void copy(int d) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if(map[i][j]<=d) mapCopy[i][j] = 0;
			else mapCopy[i][j] = map[i][j];
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (mapCopy[ny][nx] != 0 && visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
			depth[map[i][j]] = true;
		}
	}

	for (int i = 0;i < 101;i++) {
		if (depth[i] == true) v.push_back(i);
	}


	for (int i = 0;i < v.size();i++) {
		copy(v[i]);
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				if (mapCopy[j][k] != 0 && visited[j][k] == false) {
					bfs(j, k);
					cnt++;
				}
			}
		}
		cntVector.push_back(cnt);
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(mapCopy, 0, sizeof(mapCopy));
	}

	sort(cntVector.begin(), cntVector.end(), greater<int>());

	if (cntVector.size() == 1) cout << 1 << "\n";
	else cout << cntVector.front() << "\n";
	return 0;
}