#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void nodeAtDistancekDown(BinaryTreeNode<int>*node, int k) {
	if (root == NULL)
		return;

	if (k == 0) {
		cout << root->data;
		return;
	}
	nodeAtDistancekDown(root->left, k - 1);
	nodeAtDistancekDown(root->right, k - 1);

}

int nodeAtDistanceKHelper(BinaryTreeNode<int>* node, int target, int k) {
	if (root == NULL)
		return -1;

	if (node->data == target) {
		nodeAtDistancekDown(node, k);
		return 0;
	}

	int leftD = nodeAtDistanceKHelper(node->left, target, k);
	if (leftD != -1) {
		if (leftD + 1 == k) {
			cout << root->data;
		}
		else
			nodeAtDistancekDown(node->right, k - leftD - 2);
		return 1 + leftD;
	}

	int rightD = nodeAtDistanceKHelper(node->right, target, k);
	if (rightD != -1) {
		if (rightD + 1 == k) {
			cout << node->data;
		}
		else
			nodeAtDistancekDown(node->left, k - rightD - 2);
		return 1 + rightD;
	}
	return -1;
}

void nodeAtDistanceK(BinaryTreeNode<int>* root, int node, int k) {
	nodeAtDistanceKHelper(root, node, k);
}