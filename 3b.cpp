#include <iostream>
#include <string>
#include <utility>// pair
#include <queue>
using namespace std;

int	main()
{
	int	n, q, time, cntTime = 0;
	string	name;
	queue<pair<string, int>> que;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> name >> time;
		que.push(make_pair(name, time));
	}
	while (!que.empty()) {
		pair<string, int> top = que.front();
		que.pop();
		if (top.second <= q) {
			cntTime += top.second;
			cout << top.first << " " << cntTime << endl;
		} else {
			cntTime += q;
			que.push(make_pair(top.first, top.second - q));
		}
	}
}