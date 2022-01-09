#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
#include<queue>
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

void printLevelWise(BinaryTreeNode<int>* root) {
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		if (root->left == NULL && root->right == NULL) {
			cout << root->data << "L:-1,R:-1" << endl;
		}
		else if (root->left == NULL && root->right != NULL) {
			pendingNodes.push(root->right);
			pendingNodes.pop();
			cout << root->data << "L:-1,R:" << root->right->data << endl;
		}
		else if (root->left != NULL && root->right == NULL) {
			pendingNodes.push(root->left);
			pendingNodes.pop();
			cout << root->data << "L:" << root->left->data << "R:-1"   << endl;
		}
		else {
			pendingNodes.push(root->left);
			pendingNodes.push(root->right);
			pendingNodes.pop();
		}
	}
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL)
		cout << "L" << root->left->data;

	if (root->right != NULL)
		cout << "R" << root->right->data;

	cout << endl;
	printTree(root->left);
	printTree(root->right);
}
int countNode(BinaryTreeNode<int>* root) {
	if (root == NULL) return 0;
	int ans = 1;
	ans += countNode(root->left);
	ans += countNode(root->right);
	return ans;

}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printLevelWise(root);
	delete root;
}