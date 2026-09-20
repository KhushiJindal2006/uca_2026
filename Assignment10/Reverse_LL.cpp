#include<iostream>
using namespace std;

class Node {
public:

	int data;
	Node* next;

	Node(int val){
	   data=val;
	   next=NULL;
	}
};


Node* reverseList(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}

	Node* newhead=reverseList(head->next);

	head->next->next=head;
	head->next=NULL;

	return newhead;
}
