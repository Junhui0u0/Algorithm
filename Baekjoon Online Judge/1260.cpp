#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[1001];
bool check[1001];

void dfs(int start) {
	check[start] = true;
	cout << start << " ";
	for (int i = 0;i < v[start].size();i++) {
		int next = v[start][i];
		if (!check[next]) dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, start;
	int a, b;

	cin >> n >> m >> start;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1;i <= n;i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	cout << "\n";
	memset(check, false, sizeof(check));	//#cstring 사용
	bfs(start);

	return 0;
}