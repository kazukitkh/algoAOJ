#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
struct	Node {
	int	key;
	int	parent;
	int	left;
	int	right;
	int	dpt;
};
Node	Nodes[251];
int	id = 1, n, i, lf, rg, dpt = 1, ind = 2;
int	type = 0;

void	Binary() {
	int	num = pow(2, dpt);
	int	tmp = ind;
	while (num-- && n--) {
		scanf("%d", i);
		type = (type + 1) % 2;
		Nodes[i].parent = ind / 2;
		Nodes[i].dpt = dpt;
		if (type) {
			Nodes[ind / 2].left = Nodes[i].key = i;
		} else {
			Nodes[ind / 2].right = Nodes[i].key = i;
		}
		ind++;
	}
	dpt++;
	ind = tmp * 2;
	Binary();
}

int main() {
	int	key;
	scanf("%d", &n);
	Nodes[1].key = key;
	Binary();
	printf("node 1: key = %d, ", Nodes[1].key);
	if (ind >= 2) {
		printf("left key = %d, right key = %d, \n", Nodes[1].left, Nodes[1].right);
		for (int i = 2; i <= ind; i++) {
			printf("node %d: key = %d, parent key = %d, ", i, Nodes[i].key, Nodes[i].parent);
			if (Nodes[i].dpt < dpt)
				printf("left key = %d, right key = %d, \n", Nodes[i].left, Nodes[i].right);
			else
				printf("\n");
		}
	} else {
		printf("\n");
	}
}