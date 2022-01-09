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


void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout <<  temp->data << " ";
		temp = temp->next;
	}
}

//1st approach is
// Node* SkipnDeletM(Node *head, int m, int n) {
// 	if (m == 0 || head == NULL)
// 		return NULL;

// 	if (n == 0)
// 		return head;

// 	Node *temp = head;
// 	Node *t1 = head;
// 	Node *t2 = NULL;

// 	while (temp != NULL) {
// 		int c1 = 1;
// 		int c2 = 1;

// 		while (t1 != NULL && c1 < m) {
// 			t1 = t1->next;;
// 			c1++;
// 		}
// 		if (t1 == NULL)
// 			return head;

// 		t2 = t1->next;
// 		while (c2 <= n && t2 != NULL) {
// 			t2 = t2->next;
// 			c2++;
// 		}
// 		t1->next = t2;
// 		t1 = t2;
// 	}
// 	return head;
// }

//2nd approach
Node* SkipnDeletM(Node *head, int m, int n) {
	if (m == 0 || head == NULL)
		return NULL;

	if (n == 0)
		return head;

	Node *temp = NULL;
	Node *currentNode = head;


	while (currentNode != NULL) {
		int take = 0;
		int skip = 0;

		while (currentNode != NULL && take < m) {
			if (temp == NULL) {
				temp = currentNode;
			}
			else {
				temp->next = currentNode;
				temp = currentNode;
			}
			currentNode = currentNode->next;;
			take++;
		}


		while (skip < n && currentNode != NULL) {
			currentNode = currentNode->next;
			skip++;
		}
	}

	if (temp != NULL)
		temp->next = NULL;

	return head;
}

int main() {
	Node *head = takeInput();
	print(head);
	int i, j;
	cin >> i >> j;
	head = SkipnDeletM(head, i, j);
	print(head);
	return 0;
}