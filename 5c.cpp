#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef double db;

void	koch(int n, pair<db, db> p1, pair<db, db> p2) {
	pair<db, db>	s((2 * p1.first + p2.first) / 3, (2 * p1.second + p2.second) / 3);
	pair<db, db>	t((p1.first + 2 * p2.first) / 3, (p1.second + 2 * p2.second) / 3);
	db				D = hypot(t.first - s.first, t.second - s.second);
	db				tht = acos((t.first - s.first) / D);// 0, if n = 1
	db				X = D / 2;
	db				Y = (sqrt(3) / 2) * D;
	// printf("%.8f %.8f %.8f %.8f\n\n\n", D, tht, X, Y);
	pair<db, db>	u(s.first + (X * cos(tht) - Y * sin(tht)), s.second + (X * sin(tht) + Y * cos(tht)));

	if (n) {
		koch(n - 1, p1, s);
		koch(n - 1, s, u);
		koch(n - 1, u, t);
		koch(n - 1, t, p2);
	} else {
		printf("%.8f %.8f\n", p1.first, p1.second);
		return;
	}
}

int main()
{
	int	n;
	cin >> n;
	pair<db, db> zr(0, 0), hund(100, 0);
	koch(n, zr, hund);
	printf("%.8f %.8f\n", hund.first, hund.second);
	return 0;
}