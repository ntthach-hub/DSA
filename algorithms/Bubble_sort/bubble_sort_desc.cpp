#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

void nhap_mang(int &n , int a[]){
	cout<<"nhap so phan tu cua mang: "; cin>> n;
	
	for(int i = 0; i < n ; i ++){
		cin>>a[i];
	}
}
void xuat_mang(int &n, int a[]){
	for(int i = 0; i< n; i++){
		cout<< setw(4) <<a[i];
	}
	cout<<endl;
}
void bubble_sort(int n, int a[]){
	for(int i = 0 ; i< n -1 ; i++){
		for(int j = 0 ; j < n - i - 1; j++){
			if(a[j] < a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

int main(){
	int a[100];
	int n;
	nhap_mang(n,a);
	cout<<"Mang ban dau:";
	xuat_mang(n,a);
	
	bubble_sort(n,a);
	cout<<"Mang da duoc sap xep giam dan:";
	xuat_mang(n,a);
	
	return 0;
}
