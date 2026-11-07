
#include <iostream>
using namespace std;

// Display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int l, int mid, int r) {
    int temp[1000];
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n, choice;
    int arr[1000];

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 1000) {
        cout << "Invalid array size!";
        return 0;
    }

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n--- Sorting Algorithms ---";
        cout << "\n1. Selection Sort";
        cout << "\n2. Bubble Sort";
        cout << "\n3. Insertion Sort";
        cout << "\n4. Merge Sort";
        cout << "\n5. Quick Sort";
        cout << "\n6. Heap Sort";
        cout << "\n7. Display Array";
        cout << "\n8. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                selectionSort(arr, n);
                cout << "Sorted using Selection Sort: ";
                display(arr, n);
                break;

            case 2:
                bubbleSort(arr, n);
                cout << "Sorted using Bubble Sort: ";
                display(arr, n);
                break;

            case 3:
                insertionSort(arr, n);
                cout << "Sorted using Insertion Sort: ";
                display(arr, n);
                break;

            case 4:
                mergeSort(arr, 0, n - 1);
                cout << "Sorted using Merge Sort: ";
                display(arr, n);
                break;

            case 5:
                quickSort(arr, 0, n - 1);
                cout << "Sorted using Quick Sort: ";
                display(arr, n);
                break;

            case 6:
                heapSort(arr, n);
                cout << "Sorted using Heap Sort: ";
                display(arr, n);
                break;

            case 7:
                display(arr, n);
                break;

            case 8:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 8);

    return 0;
}
