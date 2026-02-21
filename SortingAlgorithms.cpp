#include <iostream>
using namespace std;

void bubbleSort(int arr[], int item) {
    for (int i = 0; i < item - 1; i++) {
        for (int j = 0; j < item - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int item) {
    for (int i = 1; i < item; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter "<<n<<" elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "The whole original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int choice;
    cout << "Choose sorting method:" << endl;
    cout << "1 for Bubble Sort" << endl;
    cout << "2 for Insertion Sort" << endl;
    cout << "3 for Merge Sort" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        bubbleSort(arr, n);
    } else if (choice == 2) {
        insertionSort(arr, n);
    } else if (choice == 3) {
        mergesort(arr, 0, n - 1);
    } else {
        cout << "Wrong choice" << endl;
        return 0;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

