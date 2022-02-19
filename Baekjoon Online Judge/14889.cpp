//а╤гу
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[20][20];
bool visited[20] = { false, };
int minResult = 1000000000;

void func(int cnt,int pos) {	//pos:next value
	if (cnt == n / 2) {
		int start = 0;
		int link = 0;

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (visited[i] == true && visited[j] == true) start += arr[i][j];
				if (visited[i] == false && visited[j] == false) link += arr[i][j];
			}
		}
		int temp = abs(start - link);
		if (minResult > temp) minResult = temp;
		return;
	}

	for (int i = pos;i < n;i++) {
		visited[i] = true;
		func(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	func(0,0);
	cout << minResult << "\n";
	return 0;
}