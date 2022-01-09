#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while (data != -1) {
		Node *newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

Node* deleteNode(Node *head, int i) {
	int count = 0;
	Node *temp = head;
	if (i == 0) {
		if (head->next == NULL)
			head = NULL;
		else
			head = head->next;

		return head;
	}

	while (temp != NULL && count < i - 1) {
		temp = temp->next;
		count++;
	}
	if (temp != NULL) {
		Node *a = temp->next;
		temp->next = a->next;
		delete a;
	}

	return head;
}

void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout <<  temp->data << " ";
		temp = temp->next;
	}
}

int main() {
	Node *head = takeInput();
	print(head);
	int i, data;
	cin >> i;
	head = deleteNode(head, i);
	print(head);
	return 0;
}