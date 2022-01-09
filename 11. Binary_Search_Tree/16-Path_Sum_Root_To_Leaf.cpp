#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void rootToLeafPathSumToK(BinaryTreeNode<int>* root, int k, int sum, string str) {
	if (root == NULL)
		return;

	if (str == NULL)
		str = " " + root->data;
	else
		str += " " + root->data;

	sum += root->data;
	if (sum == k && root->left == NULL && root->right == NULL) {
		cout << str;
		return;
	}
	rootToLeafPathSumToK(root->left, k, sum, str);
	rootToLeafPathSumToK(root->right, k, sum, str);
}

void rootToLeafPathSumToK(BinaryTreeNode<int>* root, int k) {
	rootToLeafPathSumToK(root, k, 0, NULL);
}