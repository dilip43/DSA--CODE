#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
	if (root == NULL)
		return NULL;

	if (root->data == data) {
		vector<int>*output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	vector<int>*leftoutput = getRootToNodePath(root->left, data);
	if (leftoutput !=  NULL) {
		leftoutput->push_back(root->data);
		return leftoutput;
	}
	vector<int>*rightoutput = getRootToNodePath(root->right, data);
	if (rightoutput != NULL) {
		rightoutput->push_back(root->data);
		return rightoutput;
	}
	else {
		return NULL;
	}
}

