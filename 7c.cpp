#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
struct Node {
	int	parent = -1;
	int	left;
	int	right;
};
Node	Nodes[25];
string	strs[3] = {"Preorder", "Inorder", "Postorder"};

void	Order(int id, string type) {
	if (type == "Preorder")
		printf(" %d", id);
	if (Nodes[id].left >= 0)
		Order(Nodes[id].left, type);
	if (type == "Inorder")
		printf(" %d", id);
	if (Nodes[id].right >= 0)
		Order(Nodes[id].right, type);
	if (type == "Postorder")
		printf(" %d", id);
}

int main() {
	int	n, id, root, lf, rg;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &id, &lf, &rg);
		Nodes[id].left = lf;
		Nodes[id].right = rg;
		if (lf >= 0)
			Nodes[lf].parent = id;
		if (rg >= 0)	
			Nodes[rg].parent = id;
	}
	for (int i = 0; i < n; i++)
		if (Nodes[i].parent < 0) {
			root = i;
			break;
		}
	for (int i = 0; i < 3; i++) {
		printf(i ? "\n%s\n" : "%s\n", strs[i].c_str());
		Order(root, strs[i]);
	}
	printf("\n");
	return 0;
}