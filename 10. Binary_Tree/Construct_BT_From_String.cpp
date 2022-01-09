int findIndex(string str, int si, int ei) {
	if (si > ei) return -1;
	for (int i = si; i <= ei; i++) {
		// if open parenthesis, push it
		if (str[i] == '(')
			s.push(str[i]);

		// if close parenthesis
		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();

				// if stack is empty, this is
				// the required index
				if (s.empty())
					return i;
			}
		}
	}
	return -1;
}

Node* treeFromString(string str, int si, int ei) {
	if (si > ei) return NULL;

	Node* root = new Node(str[si] - '0');
	int index = -1;

}