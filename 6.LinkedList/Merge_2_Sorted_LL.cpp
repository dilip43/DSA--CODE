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

Node* MergeTwoList(Node *head1, Node *head2) {
	Node *head = NULL;
	Node *tail = NULL;
	if (head1->data <= head2->data) {
		head = head1;
		tail = head1;
		head1 = head1->next;
	} else {
		head = head2;
		tail = head2;
		head2 = head2->next;
	}

	while (head1 != NULL && head2 != NULL) {
		if (head1->data <= head2->data) {
			tail->next = head1;
			tail = tail->next;
			head1 = head1->next;
		}
		else {
			tail->next = head2;
			tail = tail->next;
			head2 = head2->next;
		}
	}

	while(head1!=NULL){
		tail->next=head1;
		tail=tail->next;
		head1=head1->next;
	}
	while(head2!=NULL){
		tail->next=head2;
		tail=tail->next;
		head2=head2->next;
	}
	return head;

}




int main() {
	Node *head1 = takeInput();
	print(head1);
	cout << "\n";
	Node *head2 = takeInput();
	print(head2);
	cout << "\n";
	Node *ans = MergeTwoList(head1, head2);
	print(ans);
	return 0;
}