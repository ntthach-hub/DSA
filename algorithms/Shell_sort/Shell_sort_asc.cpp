#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

void nhap_mang(int arr[], int &n){
	cout<<"Nhap n: "; cin>> n;
	
	for(int i = 0; i< n; i++){
		cin>>arr[i];
	}
}

void xuat_mang(int arr[], int &n){
	for(int i = 0; i< n; i++){
		cout<<setw(4) <<arr[i];
	}
	cout<<endl;
}

void Shell_sort(int arr[], int n){
	int i, j,hcnt, h;
	int increments[20],k;
	
	for(h = 1,i =0; h < n; i++){
		increments[i] = h;
		h = 3*h+1;
	}
	
	for(i-- ; i >= 0; i--){
		h = increments[i];
		
		for(hcnt = h; hcnt < n; hcnt ++){
			for(j = hcnt ; j < n;){
				int tmp = arr[j];
				k = j;
				while( k-h >=0 && arr[k-h]> tmp){
					arr[k] = arr[k-h];
					k-=h;
				}
				arr[k] = tmp;
				j += h;
			}
		}
	}
}
int main(){
	int arr[100];
	int n;
	nhap_mang(arr,n);
	cout << "Mang ban dau: ";
    xuat_mang(arr, n);

    Shell_sort(arr, n);

    cout << "Mang sau khi sap xep tang dan: ";
    xuat_mang(arr, n);

    return 0;
}
