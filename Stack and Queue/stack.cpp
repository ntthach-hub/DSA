#include<iostream>

using namespace std;

#define MAX 100
// LIFO: last in first out
//push
//pop
//size
//top
//empty

int stack[MAX];
int topidx = -1;

//push
void push(int x){
    if (topidx == MAX - 1) {
        cout << "Stack day\n";
        return;
    }
    stack[++topidx] = x;
}

//empty
bool empty(){
	return topidx == -1;
}

//pop
void pop(){
	if(topidx == -1){
		cout<<"Stack rong\n";
		return;
	}
	topidx--;
}
//top
int top(){
	if(topidx == -1){
		cout<<"Stack rong\n";
		return -1;
	}
	return stack[topidx];
}

//size
int size(){
	return topidx +1;
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
