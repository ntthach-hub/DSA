#include<iostream>
using namespace std;

struct Sinhvien{
	string mssv;
	string ten;
};

struct Node{
	Sinhvien data;
	Node*next;
};

typedef struct Node*node;

node makenode(Sinhvien x){
	node newnode = new Node();
	newnode -> data = x;
	newnode -> next = NULL;
	return newnode;
}

// kiem tra rong 
bool empty(node head){
	return head == NULL;
}

// chen vao dau 
void insertfirst(node &head, Sinhvien x){
	node newnode = makenode(x); 
	if(head == NULL){
		head = newnode;
	}
	else{
		newnode -> next = head;
		head = newnode;
	}
}
//chen vao cuoi
void insertlast(node &head, Sinhvien x){
	node newnode = makenode(x);
	if(head == NULL){
		head = newnode;
	}else{
		node curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = newnode;
	}
}

//in danh sach

void printlist(node head){
	node curr = head;
	while (curr != NULL){
		cout<<curr->data.mssv<<" "<<curr -> data.ten<<endl;
		curr = curr -> next;
	}
	cout<<endl;
}
int main(){
	node head = NULL;
	cout << "Danh sach ban dau, empty? " << (empty(head) ? "YES" : "NO") << endl;
	
    Sinhvien sv1 = {"SV001", "Nguyen Van A"};
    Sinhvien sv2 = {"SV002", "Tran Thi B"};
	Sinhvien sv3 = {"3123", "Pham Hoang Tien"};
	
	//chen vao dau danh sach lien ket
	insertfirst(head,sv1);
	insertfirst(head,sv2);
	printlist(head);
	
	cout<<"sau khi chen vao cuoi la sv 3: ";
	insertlast(head, sv3);
	printlist(head);
	
	return 0;
}
