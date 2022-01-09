#include<bits/stdc++.h>
#include<climits>
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

TreeNode<int>* findNextLargest(TreeNode<int>* root, int n) {
	TreeNode<int>* ans;
	if (root->data > n) {
		ans = root;
	}
	else
		ans = nullptr;

	for (int i = 0; i < root->children.size(); i++) {
		TreeNode<int>* temp = findNextLargest(root->children[i], n);
		if (ans == null) {
			ans = temp;
		}
		else {
			if (temp != NULL && (temp->data < ans->data)) {
				ans = temp;
			}
		}
	}
	return ans;
}


int main() {

	TreeNode<int>* root = takeInputLevelWise();
	cout << endl;
	printLevelWise(root);
	cout << largest(root);
	return 0;
}