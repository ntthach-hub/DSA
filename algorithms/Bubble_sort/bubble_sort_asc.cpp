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
void Bubble_sort(int a[], int n)
{
	for(int i = 0; i < n - 1; i ++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}

int main(){
	int a[] = {6,2,1,6,2,7,10,3};
	int n = sizeof(a) / sizeof(a[0]); 
	
    cout << "Mang ban dau: ";
    xuat_mang(a, n);

    Bubble_sort(a, n);

    cout << "Mang sau khi sap xep tang dan: ";
    xuat_mang(a, n);

    return 0;
}


