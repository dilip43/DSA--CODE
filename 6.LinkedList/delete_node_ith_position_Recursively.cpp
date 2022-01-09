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

Node *deleteNode(Node *head, int pos) {
	//base case
	if (head == NULL) {
		return head;
	}
	//our work
	if (pos == 0) {
		Node *a = head->next;
		delete head;
		return head->next;
	}

	Node *x = deleteNode(head->next, pos - 1);
	head->next = x;
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
	head = deleteNode(head, i);
	print(head);
	return 0;
}