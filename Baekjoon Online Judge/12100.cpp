/*
- 완전탐색 -
1. 선을 그을 수 있는 경우의 수 -> 조합
2. 사다리게임 수행
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h;
int map[11][31];
bool visited[11][31];
int ans = 9999999;

bool ladder_game() {
	for (int i = 1;i <= n;i++) {
		int current_num = i;
		for (int j = 1;j <= h;j++) {
			if (visited[current_num][j] == true) current_num = current_num + 1;
			else if (visited[current_num - 1][j] == true) current_num = current_num - 1;
		}
		if (current_num != i) return false;
	}
	return true;
}

void select_line(int idx, int cnt) {
	if (cnt >= 4) return;

	if (ladder_game() == true) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = idx;i <= h;i++) {
		for (int j = 1;j < n;j++) {
			if (visited[j][i] == true) continue;
			if (visited[j - 1][i] == true) continue;
			if (visited[j + 1][i] == true) continue;

			visited[j][i] = true;
			select_line(i, cnt + 1);
			visited[j][i] = false;
		}
	}
}

void solution() {
	select_line(1, 0);
	if (ans == 9999999) ans = -1;
	cout << ans << "\n";
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		visited[b][a] = true;
	}
	solution();
	return 0;
}