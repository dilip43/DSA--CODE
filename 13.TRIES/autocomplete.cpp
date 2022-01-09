void autocomplete(vector<string>input, string word) {
	for (string s : input)
		add(s);

	TrieNode* node = findroot(root, word);
	if (node == NULL || node->childcount == 0)
		return;

	string output = "";
	allroottoleafpath(node, output, word);
}

TrieNode* findroot(TrieNode* root, string word) {
	if (string.size() == 0)
		return root;

	int childIndex = word[0] - 'a';
	TrieNode* child = root->children[childIndex];
	if (child == NULL)
		return NULL;

	return findroot(child, word.substr(1));
}

void allroottoleafpath(TrieNode* node, string output, string word) {
	if (node->childcount == 0) {
		if (output.size() > 0) {
			cout << word + output;
		}
		return;
	}
	if (node->isTerminal == true) {
		cout << word + output;
	}
	for (int i = 0; i < node->children.size(); i++) {
		if (node->children[i] != NULL) {
			string ans = output + node->children[i]->data;
			allroottoleafpath(node->children[i], ans, word);
		}
	}
}