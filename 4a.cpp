#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int	n;
	cin >> n;
	vector<int>	vc(n);
	for (int i = 0; i < n; i++)
		cin >> vc[i];
	int	ans = 0, q, a;
	cin >> q;
	sort(vc.begin(), vc.end());
	while (q--) {
		cin >> a;
		if (binary_search(vc.begin(), vc.end(), a))
			ans++;
	}
	cout << ans << endl;
}