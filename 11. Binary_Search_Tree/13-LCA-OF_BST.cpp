#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

int lcaBST(BinaryTreeNode<int>*root, int n1, int n2) {
	int lca = 0;
	if (root == NULL)
		return -1;

	if (root->data == n1 || root->data == n2) {
		return root->data;
	}

	if (root->data > n1 && root->data > n2) {
		lca = lcaBST(root->left, n1, n2);
	}

	else if (root->data < n1 &&  root->data < n2) {
		lca = lcaBST(root->right, n1, n2);
	}
	else {

		int leftlca = lcaBST(root->left, n1, n2);
		int rightlca = lcaBST(root->right, n1, n2);

		if (leftlca != -1 && rightlca == -1)
			return leftlca;

		if (leftlca == -1 && rightlca != -1)
			return rightlca;

		else if (leftlca == -1 && rightlca == -1)
			return -1;

		else
			return root->data;
	}
	return lca;
}