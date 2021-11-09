#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int	cnt = 0;
const int	SENTINEL = 2e9;

void	merge(int A[], int left, int mid, int right){
	int	n1 = mid - left;
	int	n2 = right - mid;
	int	L[n1 + 1], R[n2 + 1];
	L[n1] = R[n2] = SENTINEL;
	for (int i = 0; i < n1; i++)
		L[i] = A[i + left];
	for (int i = 0; i < n2; i++)
		R[i] = A[i + mid];
	int	j = 0, k = 0;
	for (int i = 0; i < n1 + n2; i++) {
		cnt++;
		if (L[j] <= R[k])
			A[i + left] = L[j++];
		else
			A[i + left] = R[k++];
	}
}

void	mergeSort(int A[], int left, int right) {
	if (left + 1 < right) {
		int	mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
		return ;
	}
}

int main()
{
	int	n;
	cin >> n;
	int	A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	mergeSort(A, 0, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " \n"[i == n - 1];
	cout << cnt << endl;
	return 0;
}