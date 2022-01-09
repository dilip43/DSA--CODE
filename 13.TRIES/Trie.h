class Trie {
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode *root, String word) {
		//Base case
		if (word.size() == 0) {
			root->isTerminal = true;
			return;
		}
		int Index = word[0] - 'a';
		TrieNode *child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		//recursive call
		insertWord(child, word.substr(1));
	}

	bool search(TrieNode *root, string word) {
		if (word.size() == 0) {
			return root->isTerminal;
		}
		int Index = word[0] - 'a';
		TrieNode* child;
		if (root->children[index] == NULL) {
			return false;
		}
		return search(child, word.substr(1));
	}

	void removeWord(TrieNode *root, string word) {
		if (word.size() == 0) {
			root->isTerminal = false;
			return;
		}
		int index = word[0] - 'a';
		TrieNode *child; root->children[index];

		if (child == NULL)
			return;

		removeWord(child, word.substr(1));

		//remove child node if it is useless
		if (child->isTerminal == false) {
			for (int i = 0; i < 26; i++) {
				if (child->children[i] != NULL) {
					return;
				}
				delete child;
				root->children[index] = NULL;
			}
		}

		void insertWord(String word) {
			insertWord(root, word);
		}

		bool search(string word) {
			return search(root, word);
		}

		void removeWord(string word) {
			removeWord(root, word);
		}

	};