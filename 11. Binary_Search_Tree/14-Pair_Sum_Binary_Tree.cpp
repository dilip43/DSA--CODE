#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

bool pairsumBinaryTreeUse(BinaryTreeNode<int>* mainroot, int val) {
	if (mainroot == NULL) {
		return false;
	}

	if (mainroot->data == val) {
		mainroot->data = INT_MIN;
		return true;
	}
	bool ispresent = pairsumBinaryTreeUse(mainroot->left, val);
	if (ispresent == true) {

		return true;
	}
	return ispresent = pairsumBinaryTreeUse(mainroot->right, val);
}

void pairsumBinaryTree(BinaryTreeNode<int>* node, int sum, BinaryTreeNode<int>* root) {
	if (node == NULL)
		return;

	if (node->data != INT_MIN) {
		int pair = node->data;
		int val = sum - pair;
		bool ispresent = pairsumBinaryTreeUse(root, val);
		if (ispresent == true) {
			cout << min(pair, val) << " " << max(pair, val);
		}
	}
	pairsumBinaryTree(node->left, sum, root);
	pairsumBinaryTree(node->right, sum, root);
}

void nodesumtos(BinaryTreeNode<int>* root, int sum) {
	paisumBinaryTree(root, sum, root);
}