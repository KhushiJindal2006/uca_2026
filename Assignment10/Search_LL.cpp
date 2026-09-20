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

bool SearchList(Node* list1 , Node* list2){
	if(list1==NULL) return true;

	while(list2!=NULL){
	   Node* temp1=list1;
	   Node* temp2=list2;

	   while(temp1!=NULL && temp2!=NULL && temp1->data==temp2->data){
		   temp1=temp1->next;
		   temp2=temp2->next;
	   }

	   if(temp1==NULL){
		   return true;
           }

	   list2=list2->next;
        }

	return false;
}
