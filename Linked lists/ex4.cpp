#include<iostream>
using namespace std;

struct Node{
	int data;
	Node*next;
};
typedef struct Node*node;

node makenode(int x){
	node newnode = new Node();
	newnode -> data = x;
	newnode -> next = NULL;
	return newnode;
}
int size(node head)
{
	int cnt = 0;
	node curr = head;
	while ( curr != NULL){
		++cnt;
		curr = curr -> next;
	}
	return cnt;
}
void insertfirst(node &head, int x){
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
void insertmid(node &head , int x, int pos){
	int n = size(head);
	if(pos <=0 || pos > n +1){
		cout<<"vi tri can chen khong hop le";
		return;
	}
 	node newNode = makenode(x);

    // chen dau (hoac danh sach rong)
    if (head == NULL || pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    // tim node dung TRUOC vi tri can chen: (pos - 1)
    node curr = head;
    int i = 1;  // curr dang o vi tri 1

    while (i < pos - 1 && curr->next != NULL){
        curr = curr->next;
        ++i;
    }

    // chen newNode vao sau curr
    newNode->next = curr->next;
    curr->next = newNode;
}
//insertion sort
void sort(node &head){
	if(head == NULL || head -> next == NULL) return; // 0 hoac 1 phan tu thi khoi sort
	
	for(node p = head -> next; p != NULL; p= p -> next){
		for (node q = head; q != p; q = q -> next){
			if(q->data > p ->data){
				//doi gia tri data
				int tmp = q -> data;
				q -> data = p ->data;
				p ->data = tmp;
			}
		}
	}
}

// tra ve vi tri (1-based) cua x trong danh sach
// neu khong tim thay -> tra ve -1
int findnode(node head, int x){
	int pos = 1;
	node curr = head;
	while(curr != NULL){
		if(curr -> data == x){
			return pos;  // tim thay -> tra ve vi tri hien tai
		}
		curr = curr -> next;	
		++pos;
	}
	return -1;
}

//tim gia tri nho nhat
int findmin(node head){
	if(head == NULL)
		return 0;
	
	int minval = head -> data;
	node curr = head -> next;
	
	while(curr != NULL){
		if(curr -> data < minval)
			minval = curr -> data;
		curr = curr -> next;
	}
	return minval;
}

void printList(node head){
	while(head != NULL){
		cout<<head -> data<<" ";
		head = head -> next;
	}
	cout<<endl;
}

int main(){
	node head = NULL;
	
	insertfirst(head, 10);  
    insertfirst(head, 5);    
	insertmid(head, 15,2);  
	insertmid(head, 23, 4);
    insertlast(head, 5);	
    insertlast(head, 10);
    insertlast(head, 3);
    insertlast(head, 20);
    insertlast(head, 7);
    cout<<"Danh sach:"; 
    printList(head);
    
    cout<<"sau khi sap xep tang dan: ";
	sort(head);
	printList(head);
	
	int x = 10;
	int pos = findnode(head, x);
	
	if (pos != -1){
  		cout << "Tim thay " << x << " tai vi tri: " << pos << endl;
	} else {
    	cout << "Khong tim thay " << x << " trong danh sach.\n";
	}
	
	int minval = findmin(head);
	cout<<"Gia tri nho nhat :"<< minval <<endl;
	
	return 0;
}
