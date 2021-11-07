//로또의 최고 순위와 최저 순위
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	int cnt = 0;
	int min = 0;

	for (int i = 0;i < lottos.size();i++) {
		if (lottos[i] == 0) cnt++;
		else {
			for (int j = 0;j < win_nums.size();j++) {
				if (lottos[i] == win_nums[j]) {
					min++;
					break;
				}
			}
		}
	}

	int max = min + cnt;
	if (min < 2)   min = 6;
	else if (min >= 2)   min = 7 - min;

	if (max < 2)   max = 6;
	else if (max >= 2)   max = 7 - max;

	answer.push_back(max);
	answer.push_back(min);

	return answer;
}