#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
struct	S {
	int			node;
	int			parent = -1;
	int			depth = 0;
	string		type = "";
	vector<int>	arr;
};
// typedef unsigned long uint;

void makeDepth(struct S Arr[], vector<pair<int, int> > Dp)
{
	for (int i = 0; i < Dp.size(); i++) {
		Arr[Dp[i].first].depth = Dp[i].second;
		if (int size = Arr[Dp[i].first].arr.size()) {
			Arr[Dp[i].first].type = "internal node";
			vector<pair<int, int> > newDp;
			for (int j = 0; j < size; j++)
				newDp.push_back(make_pair(Arr[Dp[i].first].arr[j], Dp[i].second + 1));
			makeDepth(Arr, newDp);
		} else {
			Arr[Dp[i].first].type = "leaf";
		}
	}
}

signed main() {
	int	n, id, k, tmp;
	scanf("%d", &n);
	struct	S Arr[n];
	vector<pair<int, int> > Dp;
	for (int i = 0; i < n; i++)
		Arr[i].node = i;
	for (int i = 0; i < n; i ++) {
		scanf("%d%d", &id, &k);
		if (k) {
			for (int j = 0; j < k; j++) {
				cin >> tmp;
				Arr[id].arr.push_back(tmp);
				Arr[tmp].parent = id;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (Arr[i].parent < 0) {
			Arr[i].type = "root";
			for (int j = 0; j < Arr[i].arr.size(); j++) {
				Arr[Arr[i].arr[j]].depth = 1;
				Dp.push_back(make_pair(Arr[i].arr[j], 1));
			}
		}
	}
	makeDepth(Arr, Dp);
	for (int i = 0; i < n; i++) {
		printf("node %d: parent = %d, depth = %d, %s, [", Arr[i].node, Arr[i].parent, Arr[i].depth, Arr[i].type.c_str());
		if (int size = Arr[i].arr.size()) {
			for (int j = 0; j < size; j++)
				printf(j == size - 1 ? "%d]\n" : "%d, ", Arr[i].arr[j]);
		} else {
			printf("]\n");
		}
	}
}