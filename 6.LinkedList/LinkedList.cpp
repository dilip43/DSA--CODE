#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"

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
		} else {
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
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main() {

//statically
	// Node n1(1);
	// Node *head = &n1;
	// Node n2(2);
	// Node n3(3);
	// Node n4(4);
	// Node n5(5);
	// n1.next = &n2;
	// n2.next = &n3;
	// n3.next = &n4;
	// n4.next = &n5;
	// print(head);
	// cout << n1.data << " " << n2.data << endl;

// Dynamically
	// Node *n3 = new Node(10);
	// Node *n4 = new Node(20);
	// Node *head = n3;

	// n3->next = n4;
	Node *head = takeInput();
	print(head);



	return 0;
}