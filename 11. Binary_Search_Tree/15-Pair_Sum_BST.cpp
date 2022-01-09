#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

vector<int>sum_list(BinaryTreeNode<int>*node, vector<int>list) {
	if (node == NULL)
		return list;

	sum_list(node->left, list);
	list.add(node->data);
	sum_list(node->right, list);

	return list;
}

void printNodesSumTos(BinaryTreeNode<int>* root, int s) {
	vector<int>a1 = new vector();
	vector<int>a2 = sum_list(root, a1);
	int start = 0;
	int end = a2.size() - 1;
	while (start < end) {
		if ((a2[start] + a2[end]) == s) {
			cout << a2[start] << a2[end];
			start++;
		}
		else if ((a2[start] + a2[end]) > s) {
			end--;
		}
		else {
			start++;
		}
	}
}