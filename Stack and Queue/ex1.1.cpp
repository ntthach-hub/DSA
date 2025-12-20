
#include<iostream>
#define MAX 100
int topid = -1;
int stack[MAX];
using namespace std;

//luyen tap
void push(int x){
	if(topid == MAX -1)
		return;
	stack[++topid] = x;
}

//pop
void pop(){
	if(topid == -1){
		return;
	}
	stack[topid --];
}
//empty
bool empty(){
	return topid == -1;
}
//top
int top(){
	if(topid == -1){
		cout<<"stack rong";
		return -1;
	}
	return stack[topid];
}
int size(){
	return topid +1;
}

int main(){
	push(10);
    push(20);
    push(30);

    cout << "Top: " << top() << endl;
    cout << "Size: " << size() << endl;

    pop();

    cout << "Top sau pop: " << top() << endl;
    cout << "Empty? " << (empty() ? "Yes" : "No") << endl;
	return 0;
}
