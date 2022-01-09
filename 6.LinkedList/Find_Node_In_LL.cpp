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

int getNodeIndex(Node *head, int i) {
	if (head == NULL)
		return -1;

	Node *temp = head;
	int count = 0;
	while (temp != NULL ) {
		if (temp->data == i)
			return count;

		count++;
		temp = temp->next;
	}
	return -1;

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
	cout << "\n";
	int i;
	cin >> i;
	cout<<getNodeIndex(head,i);
	return 0;
}