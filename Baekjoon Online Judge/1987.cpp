//백트래킹
/*
알파벳을 int배열로 저장하고 싶을때: 'A' 빼기
문자'0'->숫자0으로 변환: '0'빼기
*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
string arr[20];
bool alphabetVisited[27] = { false, };	//개수:26
int dxy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int ans = 0;

void dfs(int y,int x,int cnt) {
	ans = max(ans, cnt);

	for (int i = 0;i < 4;i++) {
		int nx = x + dxy[i][1];
		int ny = y + dxy[i][0];

		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		if (alphabetVisited[arr[ny][nx] - 'A'] == false) {
			alphabetVisited[arr[ny][nx] - 'A'] = true;
			dfs(ny, nx, cnt + 1);
			alphabetVisited[arr[ny][nx] - 'A'] = false;
		}
	}
}

int main() {
	cin >> r >> c;

	for (int i = 0;i < r;i++) {
		string s;
		cin >> s;
		arr[i] = s;
	}

	alphabetVisited[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans << "\n";

	return 0;
}