#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

typedef struct Node *node;

// cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x){
	node newNode = new Node();
	newNode -> data = x;
	newNode -> next = NULL;
	return newNode;
}
// kiem tra rong 
bool empty (node head){
	return head == NULL;
}
// dem so phan tu trong danh sach
int size(node head){
	int cnt = 0;
	node curr = head;
	
	while (curr != NULL){
		++cnt;
		curr = curr -> next; // nhay sang node tiep theo
	}
	return cnt;
}

// them 1 phan tu vao dau danh sach lien ket
void insertFirst(node &head, int x){
    node newNode = makeNode(x);
    if (head == NULL){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
} 

//them vao cuoi danh sach lien ket
void insertLast(node &head, int x){
	node newNode = makeNode(x);
	if(head == NULL){
		head = newNode;
	}
	else{
		node curr = head;
		while(curr->next != NULL){
			curr = curr -> next;
		}
		curr -> next = newNode;
	}
}

//chen vao giua
void insertmid(node & head, int x, int pos){
	int n = size(head);
	if(pos <=0 || pos > n +1){
		cout<<"vi tri can chen khong hop le";
		return;
	}
	
	if(n==1){
		insertFirst(head, x); return;
	}
	else if(pos == n + 1){
		insertLast(head,x); return;
	}
	node curr = head;
	for ( int i = 1; i < pos -1; i++){
		curr = curr -> next;
	}
	node newNode = makeNode(x);
	newNode -> next = curr -> next;
	curr -> next =  newNode;
}

// xoa phan tu dau cua dslk
void detelefirst( node &head){
	if( head == NULL) return;
	head = head -> next;
}

// xoa phan tu cuoi cua dslk
void deletelast(node & head){
	if (head == NULL) return;
	node truoc = NULL, sau = head;
	while(sau -> next != NULL){
		truoc = sau;
		sau = sau -> next;
	}
	if( truoc == NULL){
		head = NULL;
	}
	else{
		truoc -> next = NULL;
	}
}

// xoa o giua
void deletemid(node & head, int pos){
	if( pos <=0	|| pos > size(head)) return ;
	node truoc = NULL, sau = head;
	for(int i = 1; i< pos ; i++){
		truoc = sau ;
		sau = sau -> next;
	}
	if(truoc == NULL){
		head = head ->next;
	}
	else{
		truoc -> next = sau -> next;
	}
}
// in danh sach lien ket
void printList(node head){
    node curr = head;
    while (curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
	node head = NULL;
 	cout << "Danh sach ban dau, empty? " << (empty(head) ? "YES" : "NO") << endl;

    // chen vao dau
    insertFirst(head, 10);   // list: 10
    insertFirst(head, 5);    // list: 5 -> 10

    cout << "Sau khi chen vao dau: ";
    printList(head);
    cout << "Size = " << size(head) << endl;

    // chen vao cuoi
    insertLast(head, 20);    // list: 5 -> 10 -> 20
    insertLast(head, 30);    // list: 5 -> 10 -> 20 -> 30

    cout << "Sau khi chen vao cuoi: ";
    printList(head);
    cout << "Size = " << size(head) << endl;

	//chen vao giua
	insertmid(head, 15,2);  // list: 5 15 10 20 30
	
	cout<< "sau khi chen vao giua: ";
	printList(head);
	cout<<"Size = "<<size(head) <<endl;
	
	// xoa phan o cuoi
	deletelast(head); // 5 15 10 20 
	cout<<"xoa phan tu o cuoi: ";
	printList(head);
	
	// xoa phan tu o giua
	deletemid(head, 3); //5 15 20
	cout<<"xoa phan tu o giua: ";
	printList(head);
	
	return 0;
}
