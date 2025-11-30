#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int binarySearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int n;
    cout << "--- Binary Search ---" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    bubbleSort(numbers);

    cout << "\nSorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    int key;
    cout << "\nEnter the number to search for: ";
    cin >> key;

    int result = binarySearch(numbers, key);

    if (result != -1) {
        cout << "\nElement " << key << " found at index " << result << "." << endl;
    } else {
        cout << "\nElement " << key << " not found in the array." << endl;
    }

    return 0;
}