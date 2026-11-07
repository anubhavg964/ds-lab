
#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, key, choice;

    cout << "Enter array size: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n1. Linear Search";
        cout << "\n2. Binary Search";
        cout << "\n3. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter element to search: ";
            cin >> key;

            int result;

            if (choice == 1) {
                result = linearSearch(arr, n, key);
            }
            else {
                // Check if array is sorted
                bool sorted = true;

                for (int i = 0; i < n - 1; i++) {
                    if (arr[i] > arr[i + 1]) {
                        sorted = false;
                        break;
                    }
                }

                if (!sorted) {
                    cout << "Binary Search requires a sorted array!\n";
                    continue;
                }

                result = binarySearch(arr, n, key);
            }

            if (result == -1)
                cout << "Element not found!";
            else
                cout << "Element found at position: " << result + 1;
        }

        else if (choice != 3) {
            cout << "Invalid choice!";
        }

    } while (choice != 3);

    return 0;
}
