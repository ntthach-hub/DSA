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

void Quick_sort(int arr[], int first, int last){
	int lower = first + 1, upper = last;
	swap(arr[first], arr[(first + last) / 2]);
	int pivot = arr[first];
	
	while(lower <= upper){
		while(pivot >= arr[lower])
			lower++;
		while(pivot < arr[upper])
			upper--;
		if(lower < upper)
			swap(arr[lower++], arr[upper--]);
		else lower++;
	}
	
	swap(arr[upper],arr[first]);
	if(first < upper -1)
		Quick_sort(arr, first, upper -1);
	if(upper + 1 < last)
		Quick_sort(arr, upper +1, last);
}
int main(){
	int arr[100];
	int n;
	nhap_mang(arr,n);
	cout << "Mang ban dau: ";
    xuat_mang(arr, n);
	
	int first = 0;
	int last = n-1;
    Quick_sort(arr, first,last);

    cout << "Mang sau khi sap xep tang dan: ";
    xuat_mang(arr, n);

    return 0;
}
