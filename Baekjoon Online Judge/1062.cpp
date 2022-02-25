#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
string word[50];
bool duplicatedCheck[27];
vector<char> s;	//조합할 단어
int ans;

void find_middle_alpha(){
	for (int i = 0;i < n;i++) {
		for (int j = 4;j < word[i].size() - 4;j++) {
			if (duplicatedCheck[word[i][j] - 'a'] == false) {
				s.push_back(word[i][j]);
			}
		}
	}
}

int check() {
	int cnt = 0;

	for (int j = 0;j < n;j++) {
		bool b = true;
		for (int k = 4;k < word[j].size() - 4;k++) {
			if (duplicatedCheck[word[j][k] - 'a'] != true) {
				b = false;
				break;
			}
		}
		if (b == true) cnt++;
	}
	return cnt;
}

void combination(int idx,int cnt) {
	if (k - 5 == cnt) {
		ans = max(ans, check());
		return;
	}

	for (int i = idx;i < 26;i++) {
		if (duplicatedCheck[i] == true) continue;
		duplicatedCheck[i] = true;
		combination(i + 1, cnt + 1);
		duplicatedCheck[i] = false;
	}
}

void solution() {
	duplicatedCheck['a' - 'a'] = true;
	duplicatedCheck['n' - 'a'] = true;
	duplicatedCheck['t' - 'a'] = true;
	duplicatedCheck['i' - 'a'] = true;
	duplicatedCheck['c' - 'a'] = true;

	find_middle_alpha();
	combination(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> word[i];
	}
	if (k < 5) cout << 0 << "\n";
	else if (k >= 5) {
		solution();
		cout << ans << "\n";
	}
	return 0;
}