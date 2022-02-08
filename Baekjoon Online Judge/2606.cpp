//dfs
/*
v∫§≈Õ ≈©±‚:101
*/
#include <iostream>
#include <vector>
using namespace std;

int cnt, n, v1, v2;
vector<int> v[101];
bool visited[101] = { false, };
int resultCnt = 0;

void dfs(int s) {
	visited[s] = true;

	for (int i = 0;i < v[s].size();i++) {
		int next = v[s][i];
		if (visited[next] == false) {
			resultCnt++;
			dfs(next);
		}
	}
	return;
}

int main() {
	cin >> cnt;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	dfs(1);
	cout << resultCnt;
	return 0;
}