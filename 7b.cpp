#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
struct	Node{
	int	parent = -1;
	int	left;
	int	right;
	int	depth;
	int	degree = 0;
	int	sibling = -1;
	int	height = -1;
};
Node	Nodes[25];

//途中
int	makeDepthHeight(int pid, int depth) {
	int	heightL = 0, heightR = 0;
	if (Nodes[pid].left >= 0 || Nodes[pid].right >= 0) {
		if (Nodes[pid].left >= 0) {
			Nodes[Nodes[pid].left].depth = depth + 1;
			heightL = makeDepthHeight(Nodes[pid].left, depth + 1);
		}
		if (Nodes[pid].right >= 0) {
			Nodes[Nodes[pid].right].depth = depth + 1;
			heightR = makeDepthHeight(Nodes[pid].right, depth + 1);
		}
	}
	Nodes[pid].height = max(heightL, heightR);
	return Nodes[pid].height + 1;
}

// int	makeHeight(int id, int height) {
// 	int	heightL, heightR;
// 	if (Nodes[id].left >= 0)
// 		heightL = makeHeight(Nodes[id].left, height + 1);
// }

int main() {
	int	n, id, lf, rg, root;
	scanf("%d", &n);
	vector<int> height[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &id, &lf, &rg);
		if (lf < 0 && rg < 0) {
			Nodes[id].height = 0;
			height[0].push_back(id);
		}
		else {
			if (lf >= 0) {
				Nodes[lf].parent = id;
				Nodes[lf].sibling = rg;
				Nodes[id].degree++;
			}
			if (rg >= 0) {
				Nodes[rg].parent = id;
				Nodes[rg].sibling = lf;
				Nodes[id].degree++;
			}
		}
		Nodes[id].left = lf;
		Nodes[id].right = rg;
	}
	for (int i = 0; i < n; i++)
		if (Nodes[i].parent < 0)
			root = i;
	makeDepthHeight(root, 0);
	for (int i = 0; i < n; i++) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, Nodes[i].parent, Nodes[i].sibling, Nodes[i].degree, Nodes[i].depth, Nodes[i].height);
		if (i == root)
			printf("root\n");
		else if (Nodes[i].left >= 0 || Nodes[i].right >= 0)
			printf("internal node\n");
		else
			printf("leaf\n");
	}

	return 0;
}