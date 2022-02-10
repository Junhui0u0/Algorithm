#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b;
vector<int> v[1001];
bool visited[1001] = { false, };
int cnt = 0;

void dfs(int start) {
	visited[start] = true;
	
	for (int j = 0;j < v[start].size();j++) {
		if (!visited[v[start][j]]) {
			dfs(v[start][j]);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1;i <= n;i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}