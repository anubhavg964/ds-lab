
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// Push operation
void push(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    cout << "Element pushed successfully!\n";
}

// Pop operation
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return;
    }

    Node* temp = top;

    cout << "Popped element: " << top->data << endl;

    top = top->next;

    delete temp;
}

// Peek operation
void peek() {
    if (top == NULL) {
        cout << "Stack is empty!\n";
    }
    else {
        cout << "Top element: " << top->data << endl;
    }
}

// Traverse operation
void traverse() {
    if (top == NULL) {
        cout << "Stack is empty!\n";
        return;
    }

    Node* temp = top;

    cout << "Stack elements: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Operations ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Traverse";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                traverse();
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
