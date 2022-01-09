#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

int replacewithlargernodesum(BinaryTreeNode<int>* root, int replace) {
	if (root == nullptr) {
		return replace;
	}
	int rightsum = replacewithlargernodesum(root->right, replace);
	root->data += rightsum;
	int leftsum = replacewithlargernodessum(root->left, root->data);
	return leftsum;
}

void replacewithlargernodesum(BinaryTreeNode<int>* root) {
	replacewithlargernodesum(root, 0);
}