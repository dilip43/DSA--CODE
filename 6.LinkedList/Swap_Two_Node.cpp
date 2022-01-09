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

//this method only swap the data of the node not the entire node
Node* Swap_Node(Node *head, int m, int n) {
	int loop = max(m, n);
	int count = 0;
	Node *temp = head;
	Node *t1 = NULL;
	Node *t2 = NULL;
	while (temp != NULL && count <= loop) {
		if (count == m) {
			t1 = temp;
			count++;
			temp = temp->next;
		}
		else if (count == n) {
			t2 = temp;
			count++;
			temp = temp->next;
		}
		else {
			temp = temp->next;
			count++;
		}
	}
	swap(t1->data, t2->data);
	return head;
}

Node* Swap_Node2(Node *head, int i, int j) {
	if (i == j)
		return head;

	Node *currentNode = head;
	Node *prev = NULL;
	Node *firstNode = NULL;
	Node *secondNode = NULL;
	Node *firstNodePrev = NULL;
	Node *secondNodePrev = NULL;

	int pos = 0;
	while (currentNode != NULL) {
		if (pos == i) {
			firstNodePrev = prev;
			firstNode = currentNode;
		}
		else if (pos == j) {
			secondNodePrev = prev;
			secondNode = currentNode;
		}
		prev = currentNode;
		currentNode = currentNode->next;
		pos += 1;
	}
	if (firstNodePrev != NULL) {
		firstNodePrev->next = secondNode;
	}
	else {
		head = secondNode;
	}
	if (secondNodePrev != NULL) {
		secondNodePrev->next = firstNode;
	}
	else {
		head = firstNode;
	}
	Node *currentfirstNode = secondNode->next;
	secondNode->next = firstNode->next;
	firstNode->next = currentfirstNode;
	return head;

}


int main() {
	Node *head = takeInput();
	print(head);
	int i, j;
	cin >> i >> j;
	head = Swap_Node2(head, i, j);
	print(head);
	return 0;
}