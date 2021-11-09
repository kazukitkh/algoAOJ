#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdlib>// atoi
#include <cstdio>// getchar
#include <string>
using namespace std;
stack <int> S;

int	solve(string str) {
	int	b = S.top();
	S.pop();
	int	a = S.top();
	S.pop();
	if (str == "-")
		return a - b;
	if (str == "*")
		return a * b;
	else
	
		return a + b;
}

int	main()
{
	string str;

	while (cin >> str) {
		if (str == "+" || str == "-" || str == "*" )
			S.push(solve(str));
		else
			S.push(atoi(str.c_str()));
		if (getchar() == '\n')
			break ;
	}
	cout << S.top() << endl;
	return 0;
}