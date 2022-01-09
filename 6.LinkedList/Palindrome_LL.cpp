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

bool palindromeLlist(Node *head) {
	if (head == NULL || head->next == NULL)
		return true;

	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next != nullptr && fast->next->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* rev = reverse_LL_Iterative(slow->next);
	ListNode* curr = head;
	while (rev != nullptr) {
		if (rev->data != curr->data) return false;
		rev = rev->next;
		curr = curr->next;
	}
	return true;

}


int main() {
	Node *head = takeInput();
	print(head);
	cout << "\n";

	bool ans = palindromeLlist(head);
	if (ans)
		cout << "true";
	else
		cout << "false";
	return 0;
}

