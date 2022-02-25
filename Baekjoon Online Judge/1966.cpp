/*priority_queue*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int cnt = 0;
		int n, m, priority;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		
		cin >> n >> m;
		for (int i = 0;i < n;i++) {
			cin >> priority;
			q.push({ i,priority });
			pq.push(priority);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (pq.top() == val) {
				pq.pop();
				cnt++;
				if (idx == m) {
					cout << cnt << "\n";
					break;
				}
			}
			else q.push({ idx,val });
		}
	}
	return 0;
}