/*
1. 입력 값이 붙어서 나온다 -> string
2. 격자 위에서 동서남북으로 움직일 수 있다.
3. 목표 지점까지의 최단 거리를 계산해야 한다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int n, m;
int arr[100][100];
bool check[100][100] = { false, };
int length[100][100];
int dxy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };		//2번:동서남북 순서대로 (순서 상관 X) 

void bfs(int x, int y) {		//3번:최단거리->bfs
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));	//2차원배열과 (x,y)축 반대
	length[y][x] = 1;
	check[y][x] = true;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int next_x = x + dxy[i][1];
			int next_y = y + dxy[i][0];

			if (next_x >= 0 && next_y >= 0 && next_x < m&&next_y < n&&arr[next_y][next_x] == 1 && check[next_y][next_x] == false) {
				length[next_y][next_x] = length[y][x] + 1;
				check[next_y][next_x] = true;
				q.push(make_pair(next_y, next_x));
			}
		}
	}
}

int main() {
	string s;

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> s;
		for (int j = 0;j < m;j++) {
			arr[i][j] = s[j] - '0';		//1번:문자->숫자로 변환
		}
	}

	bfs(0, 0);
	cout << length[n - 1][m - 1] << "\n";

	return 0;
}