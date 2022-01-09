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

int height(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

void printgivenlevel(BinaryTreeNode<int>* root, int level) {
	if (root == NULL)
		return;

	if (level == 1)
		cout << root->data << " ";
	else {
		printgivenlevel(root->left, level - 1);
		printgivenlevel(root->right, level - 1);
	}
}

void printLevelWise(BinaryTreeNode<int>* root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++) {
		printgivenlevel(root, i);
		cout << endl;
	}
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printLevelWise(root);
	delete root;
}