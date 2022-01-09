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

int findLargest(TreeNode<int>* root) {
	int max = root->data;
	for (int i = 0; i < root->children.size(); i++) {
		int smallans = findlargest(root->children[i]);
		if (smallans > max) max = smallans;
	}
	return max;
}

TreeNode<int>* findSecondLargest(TreeNode<int>* root) {
	if (root == NULL) return NULL;

	int max1 = findLargest(root);
	queue<TreeNode<int>*>pendingNodes;
	pendingNodes.push(root);
	int max2 = INT_MIN;
	TreeNode<int>*res = nullptr;
	while (!pendingNodes.empty()) {
		TreeNode<int>* frontNode = pendingNodes.front();
		int a = frontNode->data;
		pendingNodes.pop();
		if (a > max2 && a < max1) {
			res = fontNode;
			max2 = a;
		}
		for (int i = 0; i < front->children.size(); i++) {
			pendingNodes.push(fontNode->children[i]);
		}
	}
	return res;
}

int main() {

	TreeNode<int>* root = takeInputLevelWise();
	cout << endl;
	printLevelWise(root);
	cout << countLeafNode(root);
	return 0;
}