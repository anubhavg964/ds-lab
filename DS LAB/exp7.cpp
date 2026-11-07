
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Insert element (Enqueue)
void enqueue(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Element inserted successfully!\n";
}

// Delete element (Dequeue)
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!\n";
        return;
    }

    Node* temp = front;

    cout << "Deleted element: " << front->data << endl;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

// Display queue elements
void display() {
    if (front == NULL) {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = front;

    cout << "Queue elements: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Linear Queue Operations ---";
        cout << "\n1. Insert (Enqueue)";
        cout << "\n2. Delete (Dequeue)";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
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
