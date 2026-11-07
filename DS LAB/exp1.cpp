
#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int matrix[100][100];
    int sparse[100][3];
    int k = 1;

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];

            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Store matrix information
    sparse[0][0] = m;
    sparse[0][1] = n;
    sparse[0][2] = k - 1;

    cout << "\nSparse Matrix (Triplet Representation):\n";
    cout << "Row\tColumn\tValue\n";

    for (int i = 0; i < k; i++) {
        cout << sparse[i][0] << "\t"
             << sparse[i][1] << "\t"
             << sparse[i][2] << endl;
    }

    return 0;
}
