#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* sortedArrayToBST(int arr[], int low, int high) {
	f(low > high)
	return NULL;

	int mid = (low + high + 1) / 2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
	root->left = sortedArrayToBST(arr, low, mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, high);

	return root;
}

int main() {

}