#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool	binarySearch(int arr[], int t, int n)
{
	int	size;
	size = n / 2;
	
	if (arr[size - 1 + n % 2] == t) return true;
	if (n == 1)
		return false;
	if(arr[size - 1 + n % 2] >= t) {
		int	tmp[size];
		for (int i = 0; i < size; i++)
			tmp[i] = arr[i];
		if (binarySearch(tmp, t, size))
			return true;
		else
			return false;
	} else {
		int	tmp[size];
		for (int i = 0; i < size; i++)
			tmp[i] = arr[i + size + n % 2];
		if (binarySearch(tmp, t, size))
			return true;
		else
			return false;
	}
}

int main()
{
	int n, q, t, cnt = 0;
	cin >> n;
	int	vc[n];
	for (int i = 0; i < n; i++)
		cin >> vc[i];
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (binarySearch(vc, t, n))
			cnt++;
	}
	cout << cnt << endl;
}