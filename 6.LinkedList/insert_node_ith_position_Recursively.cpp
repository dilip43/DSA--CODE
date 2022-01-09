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

Node* insertNode(Node * head, int i, int data) {
	//base case
	if (head->next == NULL)
		return head;

	//our work
	if (i == 0) {
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		return head;
	}
	Node *x = insertNode(head->next, i - 1, data);
	head->next = x;
	return head;
}

void print(Node * head) {
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
	cin >> i >> data;
	head = insertNode(head, i, data);
	print(head);
	return 0;
}