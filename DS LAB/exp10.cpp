
#include <iostream>
using namespace std;

struct Node {
    string type;
    string company;
    int year;

    Node* left;
    Node* right;
};

// Create new node
Node* createNode(string type, string company, int year) {
    Node* newNode = new Node();

    newNode->type = type;
    newNode->company = company;
    newNode->year = year;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST (based on year)
Node* insert(Node* root, string type, string company, int year) {
    if (root == NULL)
        return createNode(type, company, year);

    if (year < root->year)
        root->left = insert(root->left, type, company, year);

    else if (year > root->year)
        root->right = insert(root->right, type, company, year);

    else
        cout << "Year already exists!\n";

    return root;
}

// Find minimum node
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Delete from BST using year
Node* deleteNode(Node* root, int year) {
    if (root == NULL) {
        cout << "Automobile not found!\n";
        return NULL;
    }

    if (year < root->year)
        root->left = deleteNode(root->left, year);

    else if (year > root->year)
        root->right = deleteNode(root->right, year);

    else {
        // No left child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // No right child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);

        root->type = temp->type;
        root->company = temp->company;
        root->year = temp->year;

        root->right = deleteNode(root->right, temp->year);
    }

    return root;
}

// Inorder: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->type << " "
         << root->company << " "
         << root->year << endl;

    inorder(root->right);
}

// Preorder: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->type << " "
         << root->company << " "
         << root->year << endl;

    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->type << " "
         << root->company << " "
         << root->year << endl;
}

int main() {
    Node* root = NULL;

    int choice, year;
    string type, company;

    do {
        cout << "\n--- Binary Search Tree ---";
        cout << "\n1. Insert Automobile";
        cout << "\n2. Delete Automobile";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter automobile type: ";
                cin >> type;

                cout << "Enter company: ";
                cin >> company;

                cout << "Enter year of make: ";
                cin >> year;

                root = insert(root, type, company, year);
                break;

            case 2:
                cout << "Enter year to delete: ";
                cin >> year;

                root = deleteNode(root, year);
                break;

            case 3:
                cout << "\nInorder Traversal:\n";
                inorder(root);
                break;

            case 4:
                cout << "\nPreorder Traversal:\n";
                preorder(root);
                break;

            case 5:
                cout << "\nPostorder Traversal:\n";
                postorder(root);
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
