#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

typedef struct Node*node;

node makenode(int x){
	node newnode = new Node();
	newnode -> data = x;
	newnode -> next = NULL;
	return newnode;
}

int size(node head){
	int cnt = 0;
	node curr = head ;
	while(curr!= NULL){
		++cnt;
		curr = curr -> next;
	}
	return cnt;
}

bool empty(node &head){
	return head == NULL;
}

void insertfirst(node &head , int x){
	node newnode = makenode(x);
	if(head == NULL){
		head = newnode;
	}
	else{
		newnode -> next = head;
		head = newnode;  
	}
}

void insertlast(node &head, int x){
	node newnode= makenode(x);
	if(head == NULL){
		head = newnode;
	}
	else{
		node curr = head;
		while(curr -> next != NULL){
			curr = curr ->next;
		}
		curr -> next = newnode;
	}
}

void deletef(node &head, int x){
	if(head == NULL) return;
	head = head -> next;
}

void printlist(node head){
	while(head != NULL){
		cout<<head -> data<<" ";
		head = head -> next;
	}
	cout<<endl;
}
int main(){
	node head = NULL;
	
	insertfirst(head, 12);
	insertfirst(head, 122);
	insertfirst(head, 13);
	insertlast(head,14);
	insertlast(head,15);
	insertlast(head,23);
	insertlast(head,110);
	cout<<"danh sach: ";
	printlist(head);
	
	deletef()
	
	return 0;
}
