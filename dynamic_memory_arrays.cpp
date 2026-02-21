#include <iostream>
using namespace std;

int main() {
    // ***********1D ARRAY ***********
    int size1D;
    cout << "Enter the size of the 1D array: ";
    cin >> size1D;

    int* arr1D = new int[size1D];

    cout << "Enter " << size1D << " elements for the 1D array:\n";
    for (int i = 0; i < size1D; i++) {
        cin >> *(arr1D + i);
    }

    cout << "1D Array elements:\n";
    for (int i = 0; i < size1D; i++) {
        cout << *(arr1D + i) << " ";
    }
    cout << "\n\n";

    delete[] arr1D;  // Free memory for 1D array

    // *************** 2D ARRAY **************
    int r2D, c2D;
    cout << "Enter number of rows and columns for 2D array: ";
    cin >> r2D >> c2D;

    int** arr2D = new int*[r2D];
    for (int i = 0; i < r2D; i++) {
        arr2D[i] = new int[c2D];
    }

    cout << "Enter elements for the 2D array:\n";
    for (int i = 0; i < r2D; i++) {
        for (int j = 0; j < c2D; j++) {
            cin >> *(*(arr2D + i) + j);
        }
    }

    cout << "2D Array elements:\n";
    for (int i = 0; i < r2D; i++) {
        for (int j = 0; j < c2D; j++) {
            cout << *(*(arr2D + i) + j) << " ";
        }
        cout << endl;
    }
    cout << "\n";

    for (int i = 0; i < r2D; i++) {
        delete[] arr2D[i];
    }
    delete[] arr2D;  // Free memory for 2D array

    //  ******************3D ARRAY ***************
    int r3D, c3D, d3D;
    cout << "Enter number of rows, columns, and depth for 3D array: ";
    cin >> r3D >> c3D >> d3D;

    int*** arr3D = new int**[r3D];
    for (int i = 0; i < r3D; i++) {
        arr3D[i] = new int*[c3D];
        for (int j = 0; j < c3D; j++) {
            arr3D[i][j] = new int[d3D];
        }
    }

    cout << "Enter elements for the 3D array:\n";
    for (int i = 0; i < r3D; i++) {
        for (int j = 0; j < c3D; j++) {
            for (int k = 0; k < d3D; k++) {
                cin >> *(*(*(arr3D + i) + j) + k);
            }
        }
    }

    cout << "3D Array elements:\n";
    for (int i = 0; i < r3D; i++) {
        cout << "Matrix " << i + 1 << ":\n";
        for (int j = 0; j < c3D; j++) {
            for (int k = 0; k < d3D; k++) {
                cout << *(*(*(arr3D + i) + j) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < r3D; i++) {
        for (int j = 0; j < c3D; j++) {
            delete[] arr3D[i][j];
        }
        delete[] arr3D[i];
    }
    delete[] arr3D;  // Free memory for 3D array

    return 0;
}
