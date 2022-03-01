#include <iostream>
#include <stack>
using namespace std;

int k, x;
stack<int> st;
int ans = 0;

int main() {
	cin >> k;
	while (k--) {
		cin >> x;
		if (x != 0) {
			st.push(x);
			ans += x;
		}
		else {
			ans -= st.top();
			st.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}