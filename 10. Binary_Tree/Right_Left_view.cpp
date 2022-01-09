vector<int> rightSideView(TreeNode* root) {
    vector<int>res;
    recursion(root, 0, res);
    return res;
}

void recursion(TreeNode* root, int level, vector<int>&res) {
    if (root == NULL) return ;
    if (res.size() == level) res.push_back(root->val);
    recursion(root->right, level + 1, res);
    recursion(root->left, level + 1, res);
}

void printLeftView(BinaryTreeNode<int> *root)
{
    vector<int>res
    recursion(root, 0, res);
    for (auto it : res)
        cout << res;
}

void recursion(BinaryTreeNode<int> *root, int level, vector<int>&res) {
    if (root == NULL) return;
    if (res.size() == level) res.push_back(root->data);
    recursion(root->left, level + 1, res);
    recursion(root->right, level + 1, res);
}