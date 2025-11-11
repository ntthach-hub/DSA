#include<iostream>
#include<iomanip>
#include <algorithm>  
#include <cmath>

using namespace std;

void xuat_mang(int a[],int &n){
	for(int i = 0 ; i < n; i++)
	    cout << setw(4) << a[i];  // in cach deu moi phan tu
    cout << endl;
}

void insertion_sort(int a[],int n){
	for(int i=1 ; i < n; i ++){
		int value = a[i];
		int j = i - 1;
		
		while(j >= 0 && a[j] > value){
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = value;
	}
}
int main(){
	int a[] = {6,2,1,6,2,7,10,3};
	int n = sizeof(a) / sizeof(a[0]);  // tính so phan tu mang
	
	cout << " mang ban dau: ";
	xuat_mang(a,n);
	
	insertion_sort(a,n);
	
	cout<< "mang sau khi sap xep: ";
	xuat_mang(a,n);
}
