#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> stack; // khoi tao stack
	stack.push(1);
	stack.push(5);
	stack.push(31);
	stack.push(12);
	stack.push(7);
	stack.push(4);
	
	stack.pop();// xoa phan tu khoi dinh cua stack
	stack.pop();
	
	cout<<"phan tu tren cung:"<<stack.top() << endl; //phan tu tren cung
	cout<<"size: "<<stack.size()<<endl;
	
	stack.pop();
	if(stack.empty()){
		cout<<"Empty!";
	}
	
	cout<<"size: "<<stack.size()<<endl;
	//in tat ca cac phan tu cua Stack tu dinh xuong day
	while(!stack.empty()){
		cout<<" "<<stack.top();
		stack.pop();
	}
	return 0;
}
