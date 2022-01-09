#include<bits/stdc++.h>
using namespace std;
//in this problem we only print the reverse of the linked list not actually reverse the original linked list
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

void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout <<  temp->data << " ";
		temp = temp->next;
	}
}

void reverse(Node *head) {
	if (head == NULL)
		return;


	reverse(head->next);
	cout << head->data << " ";
}

Node* reverse_LL_Recursively(Node *head) {
	if (head == NULL || head->next == NULL)
		return head;


	Node *small = reverse_LL_Recursively(head->next);
	Node *temp = small;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return small;
}

Node *reverse_LL_Recursively2(Node *head) {
	if (head == NULL || head->next == NULL)
		return head;


	Node *small = reverse_LL_Recursively2(head->next);
	Node *tail = head->next;
	tail->next = head;
	head->next = NULL;
	return small;

}

Node* reverse_LL_Iterative(Node *head) {
	Node *curr = head;
	Node *prev = NULL;
	Node *fwd = NULL;

	while (curr != NULL) {
		fwd = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fwd;
	}
	return prev;
}

main() {
	Node *head = takeInput();
	print(head);
	cout << "\n";
	head = reverse_LL_Iterative(head);
	print(head);


	return 0;
}