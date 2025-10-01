#include <iostream>
using namespace std;

int main() {
    int r;
    cout << "Enter the number of rows: ";
    cin >> r;

    int** arr = new int*[r];
    int* c = new int[r];

    for (int i = 0; i < r; i++) {
        cout << "Enter the number of columns for row " << i + 1 << ": ";
        cin >> c[i];
        arr[i] = new int[c[i]];
    }

    for (int i = 0; i < r; i++) {
        cout << "Enter " << c[i] << " elements for row " << i + 1 << ": ";
        for (int j = 0; j < c[i]; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nYour jagged array:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] c;

    return 0;
}
