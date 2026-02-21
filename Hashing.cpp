#include <iostream>
#include <vector>
using namespace std;


class HashTable {
private:
    int size;                      
    vector<vector<int>> table;  

public:
   
    HashTable(int s) {
        size = s;
        table.resize(size);
    }

   
    int hashfn(int key) {
        return key % size;
    }

   
    void insertKey(int key) {
        int index = hashfn(key);

       
        for (int x : table[index]) {
            if (x == key) {
                cout << "value pehele hi mojood hai"<<endl;
                return;
            }
        }

        table[index].push_back(key);   
        cout << "Add hogya"<<endl;
    }

    
    bool searchKey(int key) {
        int index = hashfn(key);

        for (int x : table[index]) {
            if (x == key)
                return true;
        }
        return false;
    }

  
    void deleteKey(int key) {
        int index = hashfn(key);
        vector<int>& bucket = table[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == key) {
                
                for (int j = i; j < bucket.size() - 1; j++) {
                    bucket[j] = bucket[j + 1];
                }
                
                cout << "Delete ho gya"<<endl;
                bucket.pop_back();
                return;
            }
        }

        cout << "Nahi mila"<<endl;
    }

    
    void show() {
        cout<<endl;
        cout << "Hash table"<<endl;
        for (int i = 0; i < size; i++) {
            cout << i << " index ki value: ";
            for (int x : table[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    int s;
    cout << "Enter table size: ";
    cin >> s;

    HashTable h(s);
    int choice, key;

    while (true) {
        cout << "1 Insert" << endl;
        cout << "2 Search" << endl;
        cout << "3 Delete" << endl;
        cout << "4 Show" << endl;
        cout << "5 Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key: ";
            cin >> key;
            h.insertKey(key);
        }
        else if (choice == 2) {
            cout << "Enter key: ";
            cin >> key;
            if (h.searchKey(key))
                cout << "Found"<<endl;
            else
                cout << "not found"<<endl;
        }
        else if (choice == 3) {
            cout << "Enter key: ";
            cin >> key;
            h.deleteKey(key);
        }
        else if (choice == 4) {
            h.show();
        }
        else if (choice == 5) {
            cout << "Exited"<<endl;
            break;
        }
        else {
            cout << "invalid "<<endl;
        }
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;

// class HashTable {
// private:
//     int size;
//     vector<list<int>> table;   // vector of lists

// public:
//     HashTable(int s) {
//         size = s;
//         table.resize(size);
//     }

//     int hashfn(int key) {
//         return key % size;
//     }

//     void insertKey(int key) {
//         int index = hashfn(key);

//         // check if already exists
//         for (int x : table[index]) {
//             if (x == key) {
//                 cout << "value pehle hi mojood hai" << endl;
//                 return;
//             }
//         }

//         table[index].push_back(key);
//         cout << "Add hogya" << endl;
//     }

//     bool searchKey(int key) {
//         int index = hashfn(key);

//         for (int x : table[index]) {
//             if (x == key)
//                 return true;
//         }
//         return false;
//     }

//     void deleteKey(int key) {
//         int index = hashfn(key);

//         for (auto it = table[index].begin(); it != table[index].end(); it++) {
//             if (*it == key) {
//                 table[index].erase(it);
//                 cout << "Delete ho gya" << endl;
//                 return;
//             }
//         }

//         cout << "Nahi mila" << endl;
//     }

//     void show() {
//         cout << "\nHash table" << endl;
//         for (int i = 0; i < size; i++) {
//             cout << i << " index ki value: ";
//             for (int x : table[i])
//                 cout << x << " ";
//             cout << endl;
//         }
//     }
// };

// int main() {
//     int s;
//     cout << "Enter table size: ";
//     cin >> s;

//     HashTable h(s);
//     int choice, key;

//     while (true) {
//         cout << "\n1 Insert";
//         cout << "\n2 Search";
//         cout << "\n3 Delete";
//         cout << "\n4 Show";
//         cout << "\n5 Exit";
//         cout << "\nEnter choice: ";
//         cin >> choice;

//         if (choice == 1) {
//             cout << "Enter key: ";
//             cin >> key;
//             h.insertKey(key);
//         }
//         else if (choice == 2) {
//             cout << "Enter key: ";
//             cin >> key;
//             if (h.searchKey(key))
//                 cout << "Found" << endl;
//             else
//                 cout << "Not found" << endl;
//         }
//         else if (choice == 3) {
//             cout << "Enter key: ";
//             cin >> key;
//             h.deleteKey(key);
//         }
//         else if (choice == 4) {
//             h.show();
//         }
//         else if (choice == 5) {
//             cout << "Exited" << endl;
//             break;
//         }
//         else {
//             cout << "Invalid choice" << endl;
//         }
//     }

//     return 0;
// }
