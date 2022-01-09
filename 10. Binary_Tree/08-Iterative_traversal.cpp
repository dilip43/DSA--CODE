void inorderIterative(BinaryTreeNode<int>* root) {
	stack<BinaryTreeNode<int>*>stack;
	BinaryTreeNode<int>* curr = root;
	while (!stack.empty() || curr != nullptr) {
		if (curr != nullptr) {
			stack.push(curr);
			curr = curr->left;
		}
		else {
			curr = stack.top();
			stack.pop();
			cout << curr->data << " ";
			curr = curr->right;
		}
	}
}

void preorderIterative(BinaryTreeNode<int>*root) {
	if (root == nullptr)
		return;

	stack<BinaryTreeNode<int>*>stack;
	stack.push(root);

	while (!stack.empty()) {
		BinaryTreeNode<int>* curr = stack.top();
		stack.pop();
		cout << curr->data;
		stack.push(root->right);
		stack.push(root->left);
	}
}


vector<int>postorderTraversal(TreeNode* root) { // this postorder is done using 2 stack
	vector<int>postorder;
	if (root == NULL) return postorder;
	stack<TreeNode*>st1, st2;
	st1.push(root);
	while (!st1.empty()) {
		root = st1.top();
		st1.pop();
		st2.push(root);
		if (root->left != NULL) st1.push(root->left);
		if (root->right != NULL) st1.push(root->right);
	}
	while (!st2.empty()) {
		postorder.push_back(st2.top()->val);
		st2.pop();
	}
	return postorder;
}

vector<int>postorderTraversal(TreeNode* root) { // this postorder is done using 1 stack
	vector<int>postorder;
	stack<TreeNode*>st1;
	if (root == NULL)
		return postorder;

	TreeNode* current = root;
	while (current != NULL && !st1.empty()) {
		if (current != NULL) {
			st1.push(current);
			current = current->left;
		}
		else {
			TreeNode* temp = st1.top()->right;
			if (temp == NULL) {
				temp = st1.top();
				st1.pop();
				postorder.push_back(temp->val);
				while (!st1.empty() && temp == st1.top()->right) {
					temp = st1.top();
					st1.pop();
					postorder.push_back(temp->val);
				}
			}
			else {
				current = temp;
			}
		}
	}
	return postorder;
}

