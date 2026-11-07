
#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];
bool occupied[SIZE] = {false};

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert element
void insert(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (!occupied[pos]) {
            hashTable[pos] = key;
            occupied[pos] = true;

            cout << "Element inserted successfully!\n";
            return;
        }
    }

    cout << "Hash Table is full!\n";
}

// Search element
void search(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (!occupied[pos]) {
            cout << "Element not found!\n";
            return;
        }

        if (hashTable[pos] == key) {
            cout << "Element found at index: " << pos << endl;
            return;
        }
    }

    cout << "Element not found!\n";
}

// Display hash table
void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";

        if (occupied[i])
            cout << hashTable[i];
        else
            cout << "Empty";

        cout << endl;
    }
}

int main() {
    int choice, key;

    do {
        cout << "\n--- Hashing Operations ---";
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> key;
                insert(key);
                break;

            case 2:
                cout << "Enter element to search: ";
                cin >> key;
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
