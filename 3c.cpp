#include <iostream>
#include <string>
#include <list>
using namespace std;

int	main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	string	str;
	list<int> data;
	list<int>::iterator it, l;
	int	n, x;
	cin >> n;
	while (n--) {
		cin >> str;
		cin >> x;
		if (str == "insert")
			data.push_front(x);
		else if (str == "delete") {
			for (it = data.begin(), l = data.end(); it != l; it++) {
				if (*it == x) {
					data.erase(it);
					break;
				}
			}
		} else if (str == "deleteFirst")
			data.pop_front();
		else
			data.pop_back();
	}
	for (it = data.begin(), l = --data.end(); it != l;it++)
		cout << *it << " ";
	cout << *it << endl;
	return 0;
}