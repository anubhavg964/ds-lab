
#include <iostream>
using namespace std;

#define SIZE 10

class TwoStacks {
    int arr[SIZE];
    int top1, top2;

public:
    TwoStacks() {
        top1 = -1;
        top2 = SIZE;
    }

    // Push into Stack 1
    void push1(int x) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow!\n";
            return;
        }

        arr[++top1] = x;
        cout << "Element pushed into Stack 1\n";
    }

    // Push into Stack 2
    void push2(int x) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow!\n";
            return;
        }

        arr[--top2] = x;
        cout << "Element pushed into Stack 2\n";
    }

    // Pop from Stack 1
    void pop1() {
        if (top1 == -1) {
            cout << "Stack 1 is empty!\n";
            return;
        }

        cout << "Deleted: " << arr[top1--] << endl;
    }

    // Pop from Stack 2
    void pop2() {
        if (top2 == SIZE) {
            cout << "Stack 2 is empty!\n";
            return;
        }

        cout << "Deleted: " << arr[top2++] << endl;
    }

    // Display Stack 1
    void display1() {
        if (top1 == -1) {
            cout << "Stack 1 is empty!\n";
            return;
        }

        cout << "Stack 1: ";
        for (int i = top1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Display Stack 2
    void display2() {
        if (top2 == SIZE) {
            cout << "Stack 2 is empty!\n";
            return;
        }

        cout << "Stack 2: ";
        for (int i = top2; i < SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TwoStacks s;
    int choice, value;

    do {
        cout << "\n1. Push Stack 1";
        cout << "\n2. Push Stack 2";
        cout << "\n3. Pop Stack 1";
        cout << "\n4. Pop Stack 2";
        cout << "\n5. Display Stack 1";
        cout << "\n6. Display Stack 2";
        cout << "\n7. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push1(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                s.push2(value);
                break;

            case 3:
                s.pop1();
                break;

            case 4:
                s.pop2();
                break;

            case 5:
                s.display1();
                break;

            case 6:
                s.display2();
                break;

            case 7:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 7);

    return 0;
}
