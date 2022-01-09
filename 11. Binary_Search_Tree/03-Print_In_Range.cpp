#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void printNodeFromk1Tok2(BinaryTreeNode<int>* root, int k1, int k2) {
	if (root == NULL)
		return;

	if (root->data < k1)
		printNodeFromk1Tok2(root->left, k1, k2);

	if (root->data >= k1 && root->data <= k2)
		cout << root->data;

	if (root->data < k2)
		printNodeFromk1Tok2(root->right, k1, k2);
}