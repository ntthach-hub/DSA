#include <iostream>
#include <iomanip>    // setw
#include <algorithm>  // max_element, swap
using namespace std;

void xuat_mang(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];  // in cach deu moi phan tu
    cout << endl;
}
int countSelectionsortcomparisons(int a[], int n)
{
	int count = 0;
	for(int i = 0; i< n-1; i++){
		int minidx = i;
		for(int j = i+1; j < n; j++){
			++count;
			if(a[j] < a[minidx])
				minidx = j;
		}
		swap(a[i], a[minidx]);
	}
	return count;
}

int main(){
	int a[] = {6,2,1,6,2,7,10,3};
	int n = sizeof(a) / sizeof(a[0]);  // tính so phan tu mang
	
    cout << "Mang ban dau: ";
    xuat_mang(a, n);
    
    int soSanh = countSelectionsortcomparisons(a, n);

    cout << "Mang sau khi sap xep giam dan: ";
    xuat_mang(a, n);

    cout << "So lan so sanh: " << soSanh << endl;

    return 0;
}

