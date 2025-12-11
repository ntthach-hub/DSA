//tim kiem phan tu trong mang chua duoc sap xep
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
	xuat_mang(arr,n,item);
	
	int result = seqSearch(arr, n, item);
	
	if(result == -1)
		cout<<"khong tim thay "<< item << " trong mang.\n";
	else cout<<"Tim thay "<< item << "tai vi tri index = "<< result<<endl;
	
	return 0;
}
