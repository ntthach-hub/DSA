#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>

using namespace std;

void nhap_mang(int a[],int &n){
	cout<<"Nhap so phan tu cua mang:";
	cin>>n;
	
	for (int i = 0 ; i < n; i ++){
		cout<<"a[" << i<<"]= ";
		cin>>a[i];
	}
}

void xuat_mang(int a[], int &n){
	for (int i = 0; i < n; i++)
		cout<<setw(4) <<a[i];
	cout<<endl;
}
//sap xep giam dan
void insertion_sort(int a[], int n){
	for (int i = 1; i< n; i++){
		int value = a[i];
		int j = i - 1;
		while ( j >= 0 && a[j] < value){
			a[j + 1] = a[j];
			j = j-1;
		}
		a[j +1] = value;
	}
}

int main(){
	int a[100];
	int n;
	
	nhap_mang(a,n);
	cout<<" mang ban dau";
	
	xuat_mang(a,n);
	
	insertion_sort(a,n);
	cout<<"mang sau khi sap xep giam dan:";
	xuat_mang(a,n);
	return 0;
}
