#include<iostream>
using namespace std;

int arr[100], n = 0;

void read() {
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - l;
    int a[n1], b[n2];

    for(int i = 0; i < n1; i++) a[i] = arr[l+i];
    for(int j = 0; j < n2; j++) b[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
}

void mergeSort(int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

void display() {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int ch;
    while(true) {
        cout << "\n1. Read\n2. Sort\n3. Display\n4. Exit\nEnter choice: ";
        cin >> ch;

        if(ch == 1) read();
        else if(ch == 2) mergeSort(0, n-1);
        else if(ch == 3) display();
        else if(ch == 4) return 0;
        else cout << "Invalid choice";
    }
}
