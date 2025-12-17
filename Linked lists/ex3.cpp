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
//sap xep
void sort(node &head){
	for(node p = head; p != NULL; p = p->next){
		node min = p;
		for(node q = p->next;q != NULL; q = q->next){
			if(q ->data < min->data)
				min = q;
		}
		int tmp = min -> data;
		min -> data = p->data;
		p->data = tmp;
	}
}
//tim 1 gia tri bat ky

node findnode(node head, int x){
	node curr =head;
	while(curr != NULL){
		if(curr -> data == x){
			return curr;
		}
		curr = curr -> next;	
	}
	return NULL;
}

//tim gia tri lon nhat
int findmax(node head){
	if(head == NULL){
		cout<<"danh sach rong , khong co gia tri lon nhat!";
		return 0;
	}
	
	int maxval = head -> data; 
	node curr = head -> next;
	
	while(curr != NULL){
		if(curr->data > maxval){
			maxval = curr ->data;
		}
		curr = curr ->next;
	}
	
	return maxval;
}

// in danh sach lien ket
void printList(node head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
	node head = NULL;
 	cout << "Danh sach ban dau, empty? " << (empty(head) ? "YES" : "NO") << endl;

    insertFirst(head, 10);  
    insertFirst(head, 5);    
	insertmid(head, 15,2);  
	insertmid(head, 23, 4);
    insertLast(head, 5);
    insertLast(head, 10);
    insertLast(head, 3);
    insertLast(head, 20);
    insertLast(head, 7);
    cout<<"Danh sach:"; 
    printList(head);
	
	cout<<"sau khi sap xep tang dan: ";
	sort(head);
	printList(head);

	// tim x bat ky
	int x = 15;
	node res = findnode(head, x);
	if (res != NULL){
    cout << "Tim thay " << x << " trong danh sach.\n";
	} else {
    cout << "Khong tim thay " << x << " trong danh sach.\n";
	}
	
	int maxval = findmax(head);
	cout << "Gia tri lon nhat trong danh sach: " << maxval << endl;
	
	return 0;
}
