#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// 同じ高さどうしで計算してく
int	main()
{
	stack<int> State;
	stack<pair<int, int>> Lake;
	char	ch;
	int	sum = 0, s;
	for (int i = 0; cin >> ch; i++) {
		if (ch == '\\') {
			State.push(i);
		} else if (ch == '/' && State.size() > 0) {
			sum += s = i - State.top();// top()は末尾
			while (Lake.size() > 0 && State.top() < Lake.top().first) {
				s += Lake.top().second;
				Lake.pop();
			}
			Lake.push(make_pair(State.top(), s));
			State.pop();
		}
	}
	stack<int>	ans;
	while (Lake.size() > 0) {
		ans.push(Lake.top().second);
		Lake.pop();
	}
	cout << sum << endl;
	cout << ans.size();
	while (ans.size() > 0) {
		cout << " " << ans.top();
		ans.pop();
	}
	cout << endl;
}