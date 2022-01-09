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

Node* insertNode(Node *head, int value) {
	Node *newNode = new Node(value);
	Node *temp = head;
	if (head->next == NULL) {
		if (head->data < value) {
			head->next = newNode;
			return head;
		}
		else {
			newNode->next = head;
			head = newNode;
			return head;
		}
	}
	Node *prev = NULL;
	while (temp != NULL && temp->data <= value) {
		prev = temp;
		temp = temp->next;

	}
	if (prev != NULL) {
		newNode->next = prev->next;
		prev->next = newNode;
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
	int i;
	cin >> i;
	head = insertNode(head, i);
	print(head);
	return 0;
}