#include <iostream>
#include <algorithm>
using namespace std;

int	main()
{
	int	minj, ans = 0;
	int	a;
	cin >> a;
	int	A[a];
	for (int i = 0; i < a; i++)
		cin >> A[i];
	for (int i = 0; i < a; i++) {
		minj = i;
		for (int j = i + 1; j < a; j++)
			minj = A[minj] <= A[j] ? minj : j;
		if (minj != i) {
			swap(A[minj], A[i]);
			ans++;
		}
	}
	for (int i = 0; i < a; i++)
		cout << A[i] << " \n"[i == a - 1];
	cout << ans << endl;
	return 0;
}