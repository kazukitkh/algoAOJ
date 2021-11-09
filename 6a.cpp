#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int	A[10001] = {};

void	countingSort(int n, int Arr[]) {
	int	j = 1;
	for (int i = 10000; i >= 0; i--) {
		if (!A[i])
			continue;
		else {
			while (A[i]--) {
				Arr[n - j] = i;
				j++;
			}
		}
	}
}

int main() {
	int	n, tmp;
	cin >> n;
	int	Arr[n];
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		A[tmp]++;
	}
	countingSort(n, Arr);
	for (int i = 0; i < n; i++)
		cout << Arr[i] << " \n"[i == n - 1];
	return 0;
}