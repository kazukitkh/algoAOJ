#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>
using namespace std;
typedef long long int llint;
llint	cnt = 0;

void	merge(vector<int> A, int left, int mid, int right) {
	int	n1 = mid - left, n2 = right - mid;
	vector<int>	L(n1 + 1), R(n2 + 1);
	L[n1] = R[n2] = INT_MAX;
	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[mid + i];
	int	j = 0, k = 0;
	for (int i = left; i < right; i++) {
		if (L[j] <= R[k])
			A[i] = L[j++];
		else {
			A[i] = R[k++];
			cnt += n1 - j;// why?????? 解決済み
		}
	}
}

void	mergeSort(vector<int> A, int left, int right) {
	if (left + 1 < right) {
		int	mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	int	n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	mergeSort(A, 0, n);
	cout << cnt << endl;
}