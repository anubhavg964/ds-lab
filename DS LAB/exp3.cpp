
#include <iostream>
using namespace std;

struct Node {
    int id;
    string name;
    float salary;

    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert employee at front
void insertFront(int id, string name, float salary) {
    Node* newNode = new Node();

    newNode->id = id;
    newNode->name = name;
    newNode->salary = salary;

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    cout << "Employee inserted successfully!\n";
}

// Delete employee at end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    if (head->next == NULL) {
        head = NULL;
        delete temp;
        cout << "Employee deleted!\n";
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    delete temp;

    cout << "Employee deleted successfully!\n";
}

// Display employees
void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "List is empty!\n";
        return;
    }

    cout << "\nEmployee Details:\n";

    while (temp != NULL) {
        cout << "ID: " << temp->id
             << ", Name: " << temp->name
             << ", Salary: " << temp->salary << endl;

        temp = temp->next;
    }
}

int main() {
    int choice, id;
    string name;
    float salary;

    do {
        cout << "\n1. Insert at Front";
        cout << "\n2. Delete at End";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;

                cout << "Enter Employee Name: ";
                cin >> name;

                cout << "Enter Salary: ";
                cin >> salary;

                insertFront(id, name, salary);
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
