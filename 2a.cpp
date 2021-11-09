// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

int	main()
{
	int	n;
	cin >> n;
	int	A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int	ans = 0;
	bool	flag = 1;
	while(flag) {
		flag = 0;
		for (int j = n - 1; j > 0;j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				ans++;
			}
		}
	}
}