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
	int	sibling = -1;
	int	height = 1000;
};
Node	Nodes[25];

//途中
void	makeDepth(int pid, int depth) {
	
	if (Nodes[pid].left >= 0 || Nodes[pid].right >= 0) {
		if (Nodes[pid].left >= 0)
			makeDepth(Nodes[pid].left, depth + 1);
		if (Nodes[pid].right >= 0)
			makeDepth(Nodes[pid].right, depth + 1);
	}
}

void	makeHeight() {

}

int main() {
	int	n, id, lf, rg, root;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> lf >> rg;
		if (lf < 0 && rg < 0)
			Nodes[id].height = 0;
		else {
			if (lf >= 0) {
				Nodes[lf].parent = id;
				Nodes[lf].sibling = rg;
			}
			if (rg >= 0) {
				Nodes[rg].parent = id;
				Nodes[rg].sibling = lf;
			}
		}
		Nodes[id].left = lf;
		Nodes[id].right = rg;
	}
	for (int i = 0; i < n; i++)
		if (Nodes[i].parent < 0)
			root = i;
	makeDepth(root, 0);
}