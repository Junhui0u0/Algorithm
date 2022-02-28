/*string ´Ù·ç±â*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int idx;
	string s;
	cin >> s;

	for (int i = 0;i < croatian.size();i++) {
		while (1) {
			idx = s.find(croatian[i]);
			if (idx == string::npos) break;
			s.replace(idx, croatian[i].length(), "*");
		}
	}
	cout << s.length();
	return 0;
}