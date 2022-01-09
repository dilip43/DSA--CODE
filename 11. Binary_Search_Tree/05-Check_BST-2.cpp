#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

class isBSTReturn {
public:
	bool isBST;
	int minimim;
	int maximum;
}

isBSTReturn isBST2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		isBSTReturn output;
		output.isBST = true;
		output.minimim = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	isBSTReturn leftOutput = isBST2(root->left);
	isBSTReturn rightOutput = isBST2(root->right);

	int minimum = min(root->data, min(leftOutput.minimim, rightOutput.minimim));
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
	                  leftOutput.isBST && rightOutput.isBST;
	isBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
	return output;

}