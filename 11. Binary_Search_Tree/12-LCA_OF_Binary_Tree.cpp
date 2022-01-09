#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

int lcaBinaryTree(BinaryTreeNode<int>*root, int n1, int n2) {
	if (root == NULL)
		return -1;

	if (root->data == n1 || root->data == n2) {
		return root->data;
	}

	int leftlca = lcaBinaryTree(root->left, n1, n2);
	int rightlca = lcaBinaryTree(root->right, n1, n2);

	if (leftlca != -1 && rightlca == -1)
		return leftlca;

	if (leftlca == -1 && rightlca != -1)
		return rightlca;

	else if (leftlca == -1 && rightlca == -1)
		return -1;

	else
		return root->data;
}