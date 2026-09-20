#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int val){
		data=val;
		next=NULL;
	}
};

Node* Intersection_LL(Node* head1 , Node* head2){
	Node* newHead=NULL;
	Node* tail=NULL;
	while(head1!=NULL && head2!=NULL){
		if(head1->data==head2->data){
			Node* newnode=new Node(head1->data);

			if(newHead==NULL){
				newHead=newnode;
				tail=newnode;
			}
			else{
				tail->next=newnode;
				tail=newnode;
			}
			head1=head1->next;
			head2=head2->next;
		}
		else if(head1->data<head2->data){
			head1=head1->next;
		}
		else{
			head2=head2->next;
		}
	}
	return newHead;
}
