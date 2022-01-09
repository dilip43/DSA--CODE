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
		for (int i = 0; i < front->children.size(); i++) {
			TreeNode<int>* temp = front->children[i];
			cout << temp->data << ",";
			pendingNodes.push(temp);
		}
		cout << endl;
	}
}

int countNodes(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int count = 1;
	for (int i = 0; i < root->children.size(); i++) {
		count += countNodes(root->children[i]);
	}
	return count;
}

int main() {

	TreeNode<int>* root = takeInputLevelWise();
	cout << endl;
	printLevelWise(root);
	cout << countNodes(root);
	return 0;
}