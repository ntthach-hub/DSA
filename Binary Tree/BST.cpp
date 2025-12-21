#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int key;
	Node* left;
	Node* right;
	
	Node(int k) : key(k), left(nullptr),right(nullptr){}
};

//kiem tra rong
bool isempty(Node *root){
	return root == nullptr;
}
//tim kiem 1 phan tu cu the
Node *search(Node * root, int x){
	if(root == nullptr || root -> key == x){
		return root; // tim thay (tra ve node) or khong co (nulptr)
	}
	if(x < root -> key)
		return search(root -> left, x);
	else
		return search(root -> right,x);
}

//them phan tu vao bst
Node* insert(Node*&root, int x){
	if(root == nullptr){
		root = new Node(x);
		return root;
	}
	if(x < root -> key)
		return insert(root->left, x);
	else if(x > root -> key)
		return insert(root -> right,x);
	return root;
}

//tim node co gia tri nho nhat
Node* findmin(Node*root){
	while(root&& root ->left != nullptr){
		root = root -> left;
	}
	return root;
} 

// xoa 1 phan tu khoi bst
Node* removeNode(Node*root, int x){
	if(root == nullptr) return nullptr;
	
	if(x < root-> key){
		root->left = removeNode(root -> left, x);
	}
	else if( x > root -> key)
	{
		root -> right = removeNode(root -> right,x);
	}
	else{
		//th1 : nut la
		if(root->left == nullptr && root -> right == nullptr){
			delete root;
			return nullptr;
		}
		//th2: khong co nhanh trai (chi co nhanh phai)
		else if(root -> left == nullptr){
			Node* tmp = root->right;
			delete root;
			return nullptr;
		}
		//th3: khong co nhanh phai
		else if(root -> right== nullptr){
			Node *tmp = root-> left;
			delete root;
			return nullptr;
		}
		// th4: co ca 2 nhanh trai va phai
		else{
			//lay node nho nhat ben phai
			Node*succ = findmin(root->right);
			root -> key = succ -> key ;
			root ->right = removeNode(root -> right, succ->key); //xoa node do	
		}
	}
	return root;
}

// chieu cao cua cay: dem nut
//cay rong: height = 0, cay co 1 nut height = 1;
int height (Node *root){
	if(root == nullptr)
		return 0;
	return 1+max(height(root->left),height(root -> right));
}

//kich thuoc
int size(Node* root){
	if(root == nullptr)
		return 0;
	return 1+ size(root->left) + size(root->right);
}

//so nut la
int countleaves(Node*root){
	if(root == nullptr)
		return 0;
	if(root->left == nullptr && root->right == nullptr)
		return 1;
	return countleaves(root->left) + countleaves(root -> right);
}

//duyet cay 

//Tien tu(preoder) : node -left -right
void preorder(Node*root){
	if(root == nullptr) return;
	cout<<root->key <<" ";
	preorder(root -> left);
	preorder(root -> right);
}

//trung tu(inorder) : left - node - right
void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
//hau tu(postorder): left - right - node	
void postorder(Node *root){
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}
// sao chep cay
Node* copytree(Node*root){
	if(root == nullptr) return nullptr;
	Node*newroot = new Node(root-> key);
	newroot->left = copytree(root->left);
	newroot -> right = copytree(root -> right);
	return newroot;
}

//xoa toan bo
void cleartree(Node*root){
	if(root == nullptr) return ;
	cleartree(root->left);
	cleartree(root-> right);
	delete root;
	root = nullptr;
}
int main(){
	Node *root =nullptr;
	
	// Insert
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; ++i) {
        insert(root, a[i]);             // thay vì for (int x : a)
    }

    cout << "Inorder (BST tang dan): ";
    inorder(root);
    cout << "\n";

    cout << "Preorder: ";
    preorder(root);
    cout << "\n";

    cout << "Postorder: ";
    postorder(root);
    cout << "\n";

    cout << "Size: " << size(root) << "\n";
    cout << "Height (dem nut): " << height(root) << "\n";
    cout << "So nut la: " << countleaves(root) << "\n";

    // Search
    int x = 40;
    cout << "Search " << x << ": "
         << (search(root, x) ? "TIM THAY\n" : "KHONG THAY\n");

    // Delete
    root = removeNode(root, 30);
    cout << "Inorder sau khi xoa 30: ";
    inorder(root);
    cout << "\n";

    // Copy
    Node *copyRoot = copytree(root);
    cout << "Inorder cay copy: ";
    inorder(copyRoot);
    cout << "\n";

    cleartree(root);
    cleartree(copyRoot);
	return 0;
}
