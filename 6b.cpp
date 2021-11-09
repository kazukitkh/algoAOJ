#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int	partition(int A[], int p, int r) {
	int	x = A[r];
	int	i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int main() {
	int	n;
	cin >> n;
	int	A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int k = partition(A, 0, n - 1);
	for (int i = 0; i < n; i++) {
		if (i == k)
			cout << "[";
		cout << A[i];
		if (i == k)
			cout << "]";
		cout << " \n"[i == n - 1];
	}
}