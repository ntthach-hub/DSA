// cau 2
#include<iostream>
using namespace std;
struct NODE{
	int data;
	NODE*next;
};
//2a
NODE* insertAt(NODE*& head,int x, int pos){
	if (pos < 0) return head;
	
	NODE*newNode = new NODE;
	newNode ->data =x;
	newNode -> next = NULL;
	
	if(pos == 0 || head == NULL){
		newNode->next = head;
		head = newNode;
		return head	;
	}
	
	NODE*curr = head;
	int k =0;
	while(curr!= NULL&& k<pos -1){
		curr= curr -> next;
		k++;	
	}
	
	newNode -> next = curr -> next;
	curr -> next = newNode;
	
	return head;
}
//2b
int findnode(NODE*head,int x){
	int pos = 0;
	NODE*curr = head;
	while(curr != NULL)
	{
		if(curr ->data == x){
			return pos;
		}
		curr = curr -> next;
		pos++;
	}
	return -1;
}
//Câu 2.c là: “Viet hàm tính và tri vi  giá tr? trung bình c?ng các giá tr? nguyên có trong danh sách liên k?t.”
double tbc(NODE*head){
	long long sum = 0;
	int count = 0;
	
	NODE*curr= head;
	while(curr!=NULL){
		sum += curr ->data;
		count++;
		curr = curr ->next;
	}
	if(count == 0) //danh sach rong
		return 0;
	
	return double(sum) / count;
}


void printl(NODE*head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head -> next;
	}
	cout<<endl;
}
int main(){
	NODE*head = NULL;
	
	insertAt(head, 30,0);
	insertAt(head,23,1);
	insertAt(head,22,1);
	insertAt(head,25,1);
	printl(head);
	
	
	int x = 22;
	int pos = findnode(head,x);
	if(pos != -1){
  		cout << "Tim thay " << x << " tai vi tri: " << pos << endl;
	} else {
    	cout << "Khong tim thay " << x << " trong danh sach.\n";
	}
	cout<<"trung binh cua danh sach lien ket nay la: "<< tbc(head);
	
	return 0;
}
