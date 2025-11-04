#include <iostream>
#include <iomanip>    // setw
#include <algorithm>  // max_element, swap
#include <cmath>
using namespace std;

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
			if (a[j] < a[k])
				k = j;
		}
		//swap eplement
		swap(a[i],a[k]);
	}
}

int main(){
	int a[] = {6,2,1,6,2,7,10,3};
	int n = sizeof(a) / sizeof(a[0]);  // tính so phan tu mang
	
    cout << "Mang ban dau: ";
    xuat_mang(a, n);

    Selection_sort(a, n);

    cout << "Mang sau khi sap xep tang dan: ";
    xuat_mang(a, n);

    return 0;
}

