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


int length(Node *head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout <<  temp->data << " ";
		temp = temp->next;
	}
}

Node* reverse(Node *head, int n) {
	if (n == 0 || head == NULL) {
		return head;
	}
	//self-made approach
	// Node *temp = head;
	// int len = length(head);
	// int stopPoint = len - n;
	// for (int i = 0; i < stopPoint-1; i++) {
	// 	temp = temp->next;
	// }
	// Node *h1 = temp->next;
	// Node *sp = temp->next;
	// temp->next = NULL;
	// while (h1->next != NULL) {
	// 	h1 = h1->next;
	// }
	// h1->next = head;
	// return  sp;

	//optimised approach

	Node *slow = head;
	Node *fast = head;
	Node *initalhead = head;

	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}
	while (fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	Node *temp = slow->next;
	slow->next = NULL;
	fast->next = initalhead;
	head = temp;
	return head;
}

int main() {
	Node *head = takeInput();
	print(head);
	cout << "\n";
	int i;
	cin >> i;
	Node *ans = reverse(head, i);
	print(ans);
	return 0;
}