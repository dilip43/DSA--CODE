vector<int>ans;

void nodeAtDistancekDown(TreeNode* node, int k) {
    if (node == NULL)
        return;

    if (k == 0) {
        ans.push_back(node->val);
        return;
    }
    nodeAtDistancekDown(node->left, k - 1);
    nodeAtDistancekDown(node->right, k - 1);
}

int nodeAtDistanceKHelper(TreeNode* node, TreeNode* target, int k) {
    if (node == NULL)
        return -1;

    if (node->val == target->val) {
        nodeAtDistanceDown(node, k);
        return 0;
    }

    int leftD = nodeAtDistanceKHelper(node->left, target, k);
    if (leftD != -1) {
        if (leftD + 1 == k)
            ans.push_back(node->val);
    }
    else {
        nodeAtDistancekDown(node->right, k - leftD - 2);
    }
    int rightD = nodeAtDistanceKHelper(node->right, target, k);
    if (rightD != -1) {
        if (rightD + 1 == k) {
            ans.push_back( node->val);
        }
        else
            nodeAtDistancekDown(node->left, k - rightD - 2);
        return 1 + rightD;
    }
    return -1;
}



vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    nodeAtDistanceHelper(root, target, k);
    return ans;
}