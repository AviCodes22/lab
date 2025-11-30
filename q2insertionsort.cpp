#include<iostream>
using namespace std;

int arr[100], n = 0;

void read() {
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void insertionSort() {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
        switch(ch) {
            case 1: read(); break;
            case 2: insertionSort(); break;
            case 3: display(); break;
            case 4: return 0;
            default: cout << "Invalid choice";
        }
    }
}
