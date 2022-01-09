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

int printMiddle(Node *head){
	Node *slow=head;
	Node *fast=head->next;
	while(fast != NULL && fast->next !=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	if(fast == NULL){
		return slow->data;
	}
	else{
		return slow->next->data;
	}
  return slow->data;
}
 



int main() {
	Node *head = takeInput();
	print(head);
	cout << "\n";
	cout<<printMiddle(head);
	

	return 0;
}