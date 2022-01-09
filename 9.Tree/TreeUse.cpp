#include<bits/stdc++.h>
#include"TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
	cout << "Enter root Data :";
	int rootData; cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*>pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter Num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			cout << "Enter" << i << "ith child of " << front->data << endl;
			int childData; cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void printLevelWise(TreeNode<int>* root) {
	queue<TreeNode<int>*>pendingNodes;
	pendingNodes.push(root);

	while (!pendingNodes.empty()) {
		TreeNode<int>* front = pendingNodes.front();
		cout << front->data << ":";
		pendingNodes.pop();
		int i;
		int csize = front->children.size() - 1;
		for ( i = 0; i < csize; i++) {
			TreeNode<int>* temp = front->children[i];
			cout << temp->data << ",";
			pendingNodes.push(temp);
		}
		if (front->children.size() != 0) {
			pendingNodes.push(front->children[i]);
			cout << front->children[i]->data;
		}
		cout << endl;
	}
}

TreeNode<int>* takeInput() {
	cout << "Enter Data";
	int rootData; cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	cout << "Enter num of children of" << rootData << endl;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	//edge case
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++) {
		printTree(root->children[i]);
	}
}

void deleteTree(TreeNode<int>* root) {
	for (int i = 0; i < root->children.size(); i++) {
		deleteTree(root->children[i]);
	}
	delete root;
}

int main() {

	TreeNode<int>* root = takeInputLevelWise();
	cout << endl;
	printLevelWise(root);
	delete root;
	return 0;
}
