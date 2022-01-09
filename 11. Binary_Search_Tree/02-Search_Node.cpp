#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;


BinaryTreeNode<int>* searchInBst(BinaryTreeNode<int>* root, int k) {
	BinaryTreeNode<int>* ans;
	if (root == NULL)
		return;

	if (root->data == k)
		return root;

	else if (root->data < k) {
		ans = searchInBst(root->right, k);
	}
	else
		ans = searchInBst(root->left, k);

	return ans;
}