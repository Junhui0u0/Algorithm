#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[9];
bool visited[9] = { false, };
int selected[9];
int maxResult = 0;

void cal_max() {
	int sum = 0;

	for (int i = 0;i < n - 1;i++) {
		sum += abs(selected[i] - selected[i + 1]);
	}
	maxResult = max(maxResult, sum);
}

void func(int depth) {
	if (depth == n) {
		cal_max();
		return;
	}
	
	for (int i = 0;i < n;i++) {
		if (visited[i] == true) continue;
		
		visited[i] = true;
		selected[depth] = arr[i];	//point
		func(depth + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	func(0);
	cout << maxResult << "\n";
	return 0;
}