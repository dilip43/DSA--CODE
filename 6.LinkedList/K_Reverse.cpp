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

Node* K_Reverse(Node *head, int k) {
	if (k == 0 || k == 1)
		return head;

	Node *current = head;
	Node *fwd = NULL;
	Node *prev = NULL;

	int count = 0;

	//Reverse first K nodes of linked list
	while (count < k && current != NULL) {
		fwd=current->next;
		current->next=prev;
		prev = current;
		current=fwd;
		count++;
	}
	if(fwd!=NULL){
		head->next=K_Reverse(fwd,k);
	}
	return prev;
}

int main() {
	Node *head = takeInput();
	print(head);
	int k;
	cin >> k;
	head = K_Reverse(head, k);
	print(head);
	return 0;
}




    // ListNode* sortList(ListNode* head) {
    //     if (!head || !head->next)
    //         return head;
    //     ListNode* mid = getMid(head);
    //     ListNode* left = sortList(head);
    //     ListNode* right = sortList(mid);
    //     return merge(left, right);
    // }

    // ListNode* merge(ListNode* list1, ListNode* list2) {
    //     ListNode dummyHead(0);
    //     ListNode* ptr = &dummyHead;
    //     while (list1 && list2) {
    //         if (list1->val < list2->val) {
    //             ptr->next = list1;
    //             list1 = list1->next;
    //         } else {
    //             ptr->next = list2;
    //             list2 = list2->next;
    //         }
    //         ptr = ptr->next;
    //     }
    //     if(list1) ptr->next = list1;
    //     else ptr->next = list2;

    //     return dummyHead.next;
    // }

    // ListNode* getMid(ListNode* head) {
    //     ListNode* midPrev = nullptr;
    //     while (head && head->next) {
    //         midPrev = (midPrev == nullptr) ? head : midPrev->next;
    //         head = head->next->next;
    //     }
    //     ListNode* mid = midPrev->next;
    //     midPrev->next = nullptr;
    //     return mid;
    // }
