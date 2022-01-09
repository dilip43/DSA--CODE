vector<int> getInorder(TreeNode* root) {
	vector<int>inorder;
	TreeNode *curr = root;
	while (curr != NULL) {
		if (curr->left == NULL) {
			inorder.push_back(curr->val);
			curr = curr->right;
		}
		else {
			TreeNode *prev = curr->left;
			while (prev->right && prev->right != curr) {
				prev = prev->right;
			}
			if (prev->right == NULL) {
				prev->right = curr;
				curr = curr->left;
			}
			else {
				prev->right = NULL;
				inorder.push_back(curr->val);
				curr = curr->right;
			}
		}
	}
	return inorder;
}

vector<int> getPreorder(TreeNode* root) {
	vector<int>Preorder;
	TreeNode *curr = root;
	while (curr != NULL) {
		if (curr->left == NULL) {
			Preorder.push_back(curr->val);
			curr = curr->right;
		}
		else {
			TreeNode *prev = curr->left;
			while (prev->right && prev->right != curr) {
				prev = prev->right;
			}
			if (prev->right == NULL) {
				prev->right = curr;
				Preorder.push_back(curr->val);
				curr = curr->left;
			}
			else {
				prev->right = NULL;

				curr = curr->right;
			}
		}
	}
	return Preorder;
}