//tim kiem phan tu trong mang da duoc sap xep
#include<iostream>
#include<iomanip>
using namespace std;
void nhap(int arr[], int &n, int &item) {
    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Nhap phan tu can tim: ";
    cin >> item;
}
void xuat_mang(const int arr[], int n, int item) {
    cout << "Mang: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\nPhan tu can tim: " << item << endl;
}
//sap xep tang dan
void selection_s(int arr[],int n){
	for(int i = 0; i < n -1 ; i++){
		int k = i;
		for(int j = i+1; j < n; j++){
			if(arr[j] < arr[k]){
				k = j;
			}
		}
		swap(arr[i],arr[k]);
	}
}
int seqSearch(const int arr[], int n, const int & item ){
	int loc ;
	bool found = false;
	loc = 0;
	
	while(loc < n && !found){
		if(arr[loc] == item)
			found = true;
		else	
			loc++;
	}
	if(found)
		return loc;
	else
		return -1;
}

int main (){
	int arr[100];
	int n, item;
	
	nhap(arr,n,item);
	
	cout<<"Mang ban dau: "; 
	xuat_mang(arr,n,item);
	
	// tim vi tri truoc khi sap xep
    int posBefore = seqSearch(arr, n, item);
    
	selection_s(arr,n);
        
	cout << "\nMang sau khi sap xep tang dan\n";
    xuat_mang(arr, n, item);
    
    //Vi tri sau khi sap xep
    int posAfter = seqSearch(arr, n, item);
    
    cout << "\nKet qua tim kiem:\n";
    if (posBefore == -1) {
        cout << "Phan tu " << item << " khong ton tai trong mang.\n";
    } else {
        cout << "Truoc khi sap xep, " << item 
             << " o vi tri index = " << posBefore << endl;
        cout << "Sau khi sap xep,  " << item 
             << " o vi tri index = " << posAfter << endl;
    }
	return 0;
}
