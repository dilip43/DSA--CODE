#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
	cout << "Enter root data" << endl;
	int rootData; cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of" << front->data << endl;
		int leftchildData; cin >> leftchildData;
		if (leftchildData != -1) {
			BinaryTreeNode<int>*child = new BinaryTreeNode<int>(leftchildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of" << front->data << endl;
		int rightchildData; cin >> rightchildData;
		if (rightchildData != -1) {
			BinaryTreeNode<int>*child = new BinaryTreeNode<int>(rightchildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
	if (root == NULL) return true;

	if (root->data < min || root->data > max) {
		return  false;
	}

	bool isleftok = isBST3(root->left, min, root->data - 1);
	bool isrightok = isBST3(root->right, root->data, max);
	return isleftok && isrightok;
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << isBST3(root);
}