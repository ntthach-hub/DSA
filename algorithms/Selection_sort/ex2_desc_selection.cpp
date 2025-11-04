#include <iostream>
#include <iomanip>    // setw
#include <algorithm>  // max_element, swap
#include <cmath>
using namespace std;

void nhap_mang(int a[], int &n) {
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void xuat_mang(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];  // in cach deu moi phan tu
    cout << endl;
}
void Selection_sort(int a[], int n)
{
	for (int i = 0; i< n-1; i++){
		int k = i;
		for(int j = i+1; j < n; j++){
			if (a[j] > a[k])
				k = j;
		}
		//swap eplement
		swap(a[i],a[k]);
	}
}

int main(){
	int a[100];
	int n ;
	nhap_mang(a, n);  // Nhap tu ban phim
    cout << "Mang ban dau: ";
    
    xuat_mang(a, n);

    Selection_sort(a, n);

    cout << "Mang sau khi sap xep giam dan: ";
    xuat_mang(a, n);

    return 0;
}

