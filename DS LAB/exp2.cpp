
#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    Node* next;
};

Node* head = NULL;

// Insert at specified position
void insertNode(int roll, string name, int pos) {
    Node* newNode = new Node();
    newNode->roll = roll;
    newNode->name = name;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node using roll number
void deleteNode(int roll) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student not found!\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Student deleted successfully!\n";
}

// Reverse linked list
void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    cout << "List reversed successfully!\n";
}

// Display linked list
void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "List is empty!\n";
        return;
    }

    cout << "\nStudent Details:\n";

    while (temp != NULL) {
        cout << "Roll No: " << temp->roll
             << ", Name: " << temp->name << endl;

        temp = temp->next;
    }
}

int main() {
    int choice, roll, pos;
    string name;

    do {
        cout << "\n1. Insert Student";
        cout << "\n2. Delete Student";
        cout << "\n3. Reverse List";
        cout << "\n4. Display List";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter roll number: ";
                cin >> roll;

                cout << "Enter student name: ";
                cin >> name;

                cout << "Enter position: ";
                cin >> pos;

                insertNode(roll, name, pos);
                break;

            case 2:
                cout << "Enter roll number to delete: ";
                cin >> roll;

                deleteNode(roll);
                break;

            case 3:
                reverseList();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}
