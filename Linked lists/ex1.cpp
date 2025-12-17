#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};
typedef struct Node *node;

node makenode(int x){
	node newnode = new Node();
	newnode -> data = x;
	newnode -> next = NULL;
	return newnode;
}

int size(node head){
	int cnt = 0;
	while (head != NULL){
		++ cnt;
		head = head -> next;
	}
	return cnt;
}

void chencuoi(node &head, int k){
	node newnode = makenode(k);
	if(head == NULL)
		head = newnode;
	else{
		node curr = head;
		while(curr -> next != NULL){
			curr = curr -> next;
		}
		curr -> next= newnode;
	}
}

void print(node head){
	while(head!= NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;	
}

int main(){
	node head = NULL;
	
	chencuoi(head, 20);    // list:  20
    chencuoi(head, 30);    // list:  20 -> 30

    cout << "Sau khi chen vao cuoi: ";
    print(head);
    cout << "Size = " << size(head) << endl;
	return 0;
}
