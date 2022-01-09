Node* consturctTreeUtil(int pre[], int* preIndex, int key, int min, int max, int size) {
	if (*preIndex >= size)
		return NULL;

	Node* root = NULL;

	if (key > min && key < max) {
		root = newNode(key);
		*preIndex = *preIndex + 1;

		if (*preIndex < size) {
			root->left = consturctTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);
		}
		if (*preIndex < size) {
			root->right = constructTreeUtil(pre, preIndex,
			                                pre[*preIndex],
			                                key, max, size);
		}
	}
	return root;
}


Node* consturctTree(int pre[], int size) {
	int preIndex = 0;
	return consturctTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);

}