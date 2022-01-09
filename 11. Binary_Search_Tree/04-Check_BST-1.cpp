#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

int minimum(BinaryTreeNode <int>* root) {
	if (root == NULL) return INT_MAX;

	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode <int>* root) {
	if (root == NULL) return INT_MIN;

	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return true;

	int leftmax = maximum(root->left);
	int rightmin = minimum(root->right);

	bool output = (root->data > leftmax) && (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
	return output;
}