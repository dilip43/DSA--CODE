#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void  insertDuplicate(BinaryTreeNode<int>* root) {
	BinaryTreeNode<int> oldleft;
	if (root == NULL) return;

	insertDuplicate(root->left);
	insertDuplicate(root->right);

	oldleft = root->left;
	root->left = BinaryTreeNode(root->data);
	root->left->left = oldleft;
}
