void deleteNode(Node* head, int key) {
	if (head == NULL)
		return;

	Node *curr = head, *prev;
	while (curr->data != key) {
		if (curr->next == head) {
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	if (curr->next == head) {
		head = NULL;
		free(curr);
		return;
	}
	if (curr == head) {
		prev = head;
		while (prev->next != head) {
			prev = prev->next;
		}
		head = curr->next;
		prev->next = head;
		free(curr);
	}
	else if (curr->next == head && curr == head) {

	}
}