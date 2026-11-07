
#include <iostream>
using namespace std;

struct Node {
    int collegeId;
    string collegeName;
    Node* next;
};

Node* head = NULL;

// Insert at front
void insertFront(int id, string name) {
    Node* newNode = new Node();

    newNode->collegeId = id;
    newNode->collegeName = name;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    cout << "College inserted successfully!\n";
}

// Delete at end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    // Only one node
    if (head->next == head) {
        delete head;
        head = NULL;
    }
    else {
        Node* prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    cout << "College deleted successfully!\n";
}

// Display circular linked list
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\nCollege Details:\n";

    do {
        cout << "College ID: " << temp->collegeId
             << ", College Name: " << temp->collegeName << endl;

        temp = temp->next;

    } while (temp != head);
}

int main() {
    int choice, id;
    string name;

    do {
        cout << "\n1. Insert at Front";
        cout << "\n2. Delete at End";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter College ID: ";
                cin >> id;

                cout << "Enter College Name: ";
                cin >> name;

                insertFront(id, name);
                break;

            case 2:
                deleteEnd();
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
