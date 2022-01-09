#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
#include<queue>
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
	cout << "enter root data" << endl;
	int rootData; cin >> rootData;
	if (rootData == -1) return NULL;

	BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*>pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		BinaryTreeNode<int>*front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of" << front->data << endl;
		int leftchildData; cin >> leftchilData;
		if (leftchilData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of" << front->data << endl;
		int rightchildData; cin >> rigthchildData;
		if (rigthchildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rigthchildData);
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
			cout << root->data << "L:" << root->left->data << "R:-1" <<  << endl;
		}
		else {
			pendingNodes.push(root->left);
			pendingNodes.push(root->right);
			pendingNodes.pop();
		}
	}
}

BinaryTreeNode<int>* takeInput() {
	cout << "enter data" << endl;
	int rootData; cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>root = new BinaryTreeNode(rootData);
	root->left = takeInput();
	root->right = takeInput();
	return root;
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}
	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}


int main() {
	// BinaryTreeNode<int>*root = new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int>*node1 = new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int>*node2 = new BinaryTreeNode<int>(3);
	// root->left = node1;
	// root->right = node2;
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
	delete root;
}