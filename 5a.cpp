#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, q, m;

int	solve(int A[], int idx, int s) {
	// cout << A[idx] << idx << s << endl;
	for (int i = idx; i < n - 1 || m < A[i] + A[i + 1] + s; i++) {
		if (A[i] + s == m)
			return true;
		else {
			if (solve(A, i + 1, s + A[i]))
				return true;
			else
				continue;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	int	A[n];
	int	tmp;
	int	maxA = 0, minA = 2000;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	sort(A, A + n);
	minA = A[0]; maxA = A[n - 1];
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> m;
		if (m < minA) {
			cout << "no" << endl;
			continue;
		}
		if (solve(A, 0, 0))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}