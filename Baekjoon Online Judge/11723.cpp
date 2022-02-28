#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int m, num;
string s;
vector<int> v;
bool checked[21];

void add(int x) {
	if (!checked[x]) {
		checked[x] = true;
	}
}

void remove(int x) {
	if (checked[x]) {
		checked[x] = false;
	}
}

void check(int x) {
	if (checked[x]) cout << "1\n";
	else cout << "0\n";
}

void toggle(int x) {
	if (checked[x]) {
		checked[x] = false;
	}
	else {
		checked[x] = true;
	}
}

void all() {
	memset(checked, true, sizeof(checked));
}

void empty() {
	memset(checked, false, sizeof(checked));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(checked, false, sizeof(checked));
	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "add") {
			cin >> num;
			add(num);
		}
		else if (s == "remove") {
			cin >> num;
			remove(num);
		}
		else if (s == "check") {
			cin >> num;
			check(num);
		}
		else if (s == "toggle") {
			cin >> num;
			toggle(num);
		}
		else if (s == "all") all();
		else if (s == "empty") empty();
	}
	return 0;
}