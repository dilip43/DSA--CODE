#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

LinkedList<int> BSTTOSORTEDLL(BinaryTreeNode<int>*root) {
	if (root == NULL) return NULL;

	LinkedList<int>root = new LinkedList<int>(root->data);

	LinkedList left = BSTTOSORTEDLL(root->left);
	LinkedList right = BSTTOSORTEDLL(root->right);

	if (left != NULL) {
		LinkedList<int>temp = left;
		while (temp != NULL) {
			temp = temp->next;
		}
		temp->next = root;
		root->next = right;
		return left;
	}
	else {
		root->next = head;
		return root;
	}

}