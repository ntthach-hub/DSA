#include <iostream>
#include <iomanip>
#include <algorithm>  // max_element, swap
#include <string>     // to_string
using namespace std;

// ===== Hàm in m?ng d?ng b?ng d?p =====
void print_array(int arr[], int n) {
    int max_len = to_string(*max_element(arr, arr + n)).length();

    // In ch? s?
    cout << "Ch? s?:  ";
    for (int i = 0; i < n; i++) {
        cout << setw(max_len + 3) << i;
    }
    cout << endl;

    // In khung trên
    cout << "+";
    for (int i = 0; i < n; i++) {
        cout << string(max_len + 4, '-') << "+";
    }
    cout << endl;

    // In giá tr? m?ng
    cout << "| ";
    for (int i = 0; i < n; i++) {
        cout << setw(max_len + 2) << arr[i] << " | ";
    }
    cout << endl;

    cout << "+";
    for (int i = 0; i < n; i++) {
        cout << string(max_len + 4, '-') << "+";
    }
    cout << endl;
}


void nhap_mang(int arr[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

// ===== Thu?t toán Insertion Sort (tang d?n) =====
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int value = arr[i];  // ph?n t? c?n chèn
        int j = i - 1;

        // D?i các ph?n t? l?n hon sang ph?i
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = value;

        // In t?ng bu?c d? minh h?a
        cout << "\nBu?c " << i << ": chèn " << value << endl;
        print_array(arr, n);
    }
}

// ===== Hàm main =====
int main() {
    int arr[100];
    int n;

    nhap_mang(arr, n);
    cout << "\nM?ng ban d?u:\n";
    print_array(arr, n);

    insertionSort(arr, n);

    cout << "\nM?ng sau khi s?p x?p tang d?n:\n";
    print_array(arr, n);

    return 0;
}

