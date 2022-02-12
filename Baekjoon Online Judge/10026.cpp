/*
key point: 
1. 공백x string 타입 받기
2. Green을 Red로 바꿔서 풀면, 함수를 재사용 할 수 있다. (생각의 전환)
*/
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n;
string arr[100];
bool visitedRed[100][100] = { false, };
bool visitedBlue[100][100] = { false, };
bool visitedGreen[100][100] = { false, };
bool visitedRedGreen[100][100] = { false, };
int dxy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int cntRed, cntBlue, cntGreen = 0;
int cntRedGreen = 0;
int result[2] = { 0 };

void bfsRed(int y, int x) {
	queue<pair<int, int>> qRed;
	qRed.push({ y,x });

	while (!qRed.empty()) {
		int cx = qRed.front().second;
		int cy = qRed.front().first;
		qRed.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[ny][nx] == 'R'&&visitedRed[ny][nx] == false) {
				qRed.push({ ny,nx });
				visitedRed[ny][nx] = true;
			}
		}
	}
}

void bfsGreen(int y, int x) {
	queue<pair<int, int>> qGreen;
	qGreen.push({ y,x });

	while (!qGreen.empty()) {
		int cx = qGreen.front().second;
		int cy = qGreen.front().first;
		qGreen.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[ny][nx] == 'G'&&visitedGreen[ny][nx] == false) {
				qGreen.push({ ny,nx });
				visitedGreen[ny][nx] = true;
			}
		}
	}
}

void bfsBlue(int y, int x) {
	queue<pair<int, int>> qBlue;
	qBlue.push({ y,x });

	while (!qBlue.empty()) {
		int cx = qBlue.front().second;
		int cy = qBlue.front().first;
		qBlue.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[ny][nx] == 'B'&&visitedBlue[ny][nx] == false) {
				qBlue.push({ ny,nx });
				visitedBlue[ny][nx] = true;
			}
		}
	}
}

void bfsRedGreen(int y, int x) {
	queue<pair<int, int>> qRedGreen;
	qRedGreen.push({ y,x });

	while (!qRedGreen.empty()) {
		int cx = qRedGreen.front().second;
		int cy = qRedGreen.front().first;
		qRedGreen.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dxy[i][1];
			int ny = cy + dxy[i][0];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[ny][nx] == 'R'||arr[ny][nx] == 'G') {
				if (visitedRedGreen[ny][nx] == false) {
					qRedGreen.push({ ny,nx });
					visitedRedGreen[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		arr[i] = s;
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 'R'&&visitedRed[i][j] == false) {
				bfsRed(i, j);
				cntRed++;
			}
			else if (arr[i][j] == 'G'&&visitedGreen[i][j] == false) {
				bfsGreen(i, j);
				cntGreen++;
			}
			else if (arr[i][j] == 'B'&&visitedBlue[i][j] == false) {
				bfsBlue(i, j);
				cntBlue++;
			}
		}
	}
	result[0] = cntRed + cntGreen + cntBlue;
	cntBlue = 0;
	memset(visitedBlue, false, sizeof(visitedBlue));

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 'R' || arr[i][j] == 'G') {
				if (visitedRedGreen[i][j] == false) {
					bfsRedGreen(i, j);
					cntRedGreen++;
				}
			}
			else if (arr[i][j] == 'B'&&visitedBlue[i][j] == false) {
				bfsBlue(i, j);
				cntBlue++;
			}
		}
	}
	result[1] = cntRedGreen + cntBlue;
	cout << result[0] << " " << result[1] << "\n";

	return 0;
}