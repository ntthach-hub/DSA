#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * next;
};
struct Node* top =NULL;
void push(int val){
	Node* newnode = new Node;
	newnode -> data = val;
	newnode -> next = top;
	
	top = newnode;
}

void pop(){
	if(top == NULL){
		cout<<"stack underflow"<<endl;
	} else{
		cout<<"The popped element is "<< top -> data <<endl;
		top = top -> next;
	}
}

void display(){
	struct Node* curr;
	if(top == NULL){
		cout<<"Stack is empty!";
	}
	else{
		curr = top;
		cout<< "stack element are: ";
		while(curr != NULL){
			cout<<curr -> data <<" ";
			curr = curr ->next;
		}
	}
	cout<<endl;
}

int main(){
    push(10);
    push(20);
    push(30);

    display();   // In stack hien tai

    pop();       // Pop 1 pt
    display();   // In lai stack

    pop();
    pop();
    pop(); 		//pop nua de thay thong bao underflow
    
    return 0;
}
