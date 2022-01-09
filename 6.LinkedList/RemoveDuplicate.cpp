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

Node* removeDuplicate(Node *head) {
	if ( head == NULL || head->next == NULL) {
		return head;
	}
	Node *t1 = head;
	Node *t2 = head->next;
	while (t2 != NULL) {
		if (t1->data == t2->data) {
			t2 = t2->next;
			
		}
		else {
			t1->next = t2;
			t1 = t2;
//deallocate the duplicate node have to implement.
			t2 = t2->next;
		}
	}
	t1->next = t2;
	return head;
}

int main() { 
	Node *head = takeInput();
	print(head);
	cout << "\n";
	Node *ans = removeDuplicate(head);
	print(ans);
	return 0;
}