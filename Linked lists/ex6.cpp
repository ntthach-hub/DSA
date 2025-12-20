#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// cap phat 1 node moi
Node* makeNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// kiem tra rong
bool empty(Node* head) {
    return head == NULL;
}

// dem so phan tu
int size(Node* head) {
    int cnt = 0;
    Node* curr = head;

    while (curr != NULL) {
        ++cnt;
        curr = curr->next;
    }
    return cnt;
}

// them vao dau
void insertFirst(Node* &head, int x) {
    Node* newNode = makeNode(x);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// them vao cuoi
void insertLast(Node* &head, int x) {
    Node* newNode = makeNode(x);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// chen vao giua( vi tri pos , 1 based)
void insertmid(Node* &head, int x, int pos) {
    int n = size(head);
    if (pos <= 0 || pos > n + 1) {
        cout << "vi tri can chen khong hop le";
        return;
    }

    if (n == 1) {
        insertFirst(head, x);
        return;
    } else if (pos == n + 1) {
        insertLast(head, x);
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
    }

    Node* newNode = makeNode(x);
    newNode->next = curr->next;
    curr->next = newNode;
}

//xoa phan tu dau
void deleteFirst(Node* &head) {
    if (head == NULL) return;
    head = head->next;
}

// xoa phan tu cuoi
void deleteLast(Node* &head) {
    if (head == NULL) return;

    Node* truoc = NULL;
    Node* sau = head;

    while (sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }

    if (truoc == NULL) {
        head = NULL;          // ch? có 1 ph?n t?
    } else {
        truoc->next = NULL;
    }
}

// xoa giua
void deleteMid(Node* &head, int pos) {
    if (pos <= 0 || pos > size(head)) return;

    Node* truoc = NULL;
    Node* sau = head;

    for (int i = 1; i < pos; i++) {
        truoc = sau;
        sau = sau->next;
    }

    if (truoc == NULL) {
        head = head->next;    // xóa d?u
    } else {
        truoc->next = sau->next;
    }
}
//tim phan tu lon nhat
int findmax(Node * head){
	if(head == NULL) return 0 ;
	
	int maxval = head -> data;
	Node *curr = head -> next;
	
	while(curr!= NULL){
		if(curr -> data > maxval)
			maxval = curr -> data;
		curr = curr -> next;
	}
	return maxval;
}

// sap xep
void sort(Node* head){
	for(Node* p = head; p != NULL; p = p->next){
		Node* min = p;
		for(Node * q = p -> next; q!= NULL; q = q -> next){
			if(q -> data < min->data)
				min = q;
		}
		int tmp = min -> data;
		min-> data = p ->data;
		p -> data = tmp;
	}
}

// find node
Node * findnode(Node * head, int item){
	Node * curr = head;
	while(curr != NULL){
		if(curr -> data == item)
			return curr;
		curr = curr ->next;
	}
	return NULL;
}
// in danh sách
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    cout << "Danh sach ban dau, empty? " << (empty(head) ? "YES" : "NO") << endl;

    // chen vao dau
    insertFirst(head, 10);   
    insertFirst(head, 5);    
	insertFirst(head, 1);
	insertFirst(head, 19);
	insertFirst(head, 111);
    cout << "Sau khi chen vao dau: ";
    printList(head);
    cout << "Size = " << size(head) << endl;

    // chen vao cuoi
    insertLast(head, 20);    
    insertLast(head, 30);    

    cout << "Sau khi chen vao cuoi: ";
    printList(head);
    cout << "Size = " << size(head) << endl;

    // chen vao giua
    insertmid(head, 15, 2);  
    cout << "sau khi chen vao giua: ";
    printList(head);
    cout << "Size = " << size(head) << endl;

    // xoa phan tu o cuoi
    deleteLast(head);       
    cout << "xoa phan tu o cuoi: ";
    printList(head);

    // xoa phan tu o giua
    deleteMid(head, 3);     
    cout << "xoa phan tu o giua: ";
    printList(head);
	
	
	//tim k bat ky
	int item = 20;
	Node *res = findnode(head, item);
	if (res != NULL){
    cout << "Tim thay " << item << " trong danh sach.\n";
	} else {
    cout << "Khong tim thay " << item << " trong danh sach.\n";
	}
	
	//sort 
	cout<<"sap xep tang dan: ";	
	sort(head);
	printList(head);
	
	//tim max
	int maxval = findmax(head);
	cout << "Gia tri lon nhat trong danh sach: " << maxval << endl;
	
    return 0;
}

