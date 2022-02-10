//메모리초과 문제 -> 한번 방문한 곳은 방문하지 x (visited)
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[100001] = { 0, };
int visited[100001] = { false, };
int time;

void bfs(int n, int k) {
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int a = cur - 1;
		int b = cur + 1;
		int c = cur * 2;

		if (a >= 0 && a <= 100000 && visited[a]==false) {
			q.push(a);
			arr[a] = arr[cur] + 1;
			visited[a] = true;
		}
		if (b >= 0 && b <= 100000 && visited[b] == false) {
			q.push(b);
			arr[b] = arr[cur] + 1;
			visited[b] = true;
		}
		if (c >= 0 && c <= 100000 && visited[c] == false) {
			q.push(c);
			arr[c] = arr[cur] + 1;
			visited[c] = true;
		}

		if (a == k || b == k || c == k) {
			if (a == k) time = arr[a];
			else if (b == k) time = arr[b];
			else if (c == k) time = arr[c];

			break;
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	bfs(n, k);

	if (n == k) time = 0;

	cout << time << "\n";

	return 0;
}