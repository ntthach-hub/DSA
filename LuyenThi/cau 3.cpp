#include<iostream>
#include<algorithm>
using namespace std;

struct NodeTree{
	int data;
	NodeTree*left;
	NodeTree*right;
};

NodeTree* insert(NodeTree*&root,int x){
	if(root == nullptr){
		root = new NodeTree();
		return root;
	}
	if(x < root->data){
		return insert(root->left,x);
	}
	else if(x> root ->data)
		return insert(root -> right, x);
	return root;
}

int countLeaf(NodeTree*root){
	if(root == nullptr) return 0;
	
	if(root ->left == nullptr && root -> right == nullptr) return 1;
	
	return countLeaf(root->left) + countLeaf(root->right);
}

void preorderNRL(NodeTree* root) {
    if (root == nullptr) return;
    cout << root->data << " ";     // N
    preorderNRL(root->right);      // R
    preorderNRL(root->left);       // L
}

int main(){
	
	int a[] = {23,58,99,45,66,33,15};
	int n = sizeof(a)/sizeof(a[0]);
    NodeTree* root = nullptr;   
	for(int i = 0; i< n; i++){
		insert(root,a[i]);
	}
	
    cout << "NRL: ";
    preorderNRL(root);               // n?u làm NRL
    cout << "\n";
	
	cout<<"so nut la la: "<<countLeaf(root)<<endl;
	return 0;
}
