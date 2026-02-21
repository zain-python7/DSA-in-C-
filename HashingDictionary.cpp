#include <iostream>
#include <list>
using namespace std;

struct Entry {
    string word;
    string meaning;
};

class Dictionary {
public:
    static const int SIZE = 10;
    list<Entry> table[SIZE];

    // Hash function using prime number
    int hashFunction(string key) {
        int hash = 0;
        int prime = 31;

        for (char ch : key) {
            hash = hash * prime + ch;
        }
        return hash % SIZE;
    }

    // Insert function
    void insert(string word, string meaning) {
        int index = hashFunction(word);
        table[index].push_back({word, meaning});
        cout << "Inserted: " << word << endl;
    }

    // Search function
    void search(string word) {
        int index = hashFunction(word);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->word == word) {
                cout << "Meaning of '" << word << "' is: "
                     << it->meaning << endl;
                return;
            }
        }
        cout << "Word not found!" << endl;
    }

    // Delete function
    void remove(string word) {
        int index = hashFunction(word);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->word == word) {
                table[index].erase(it);
                cout << "Deleted: " << word << endl;
                return;
            }
        }
        cout << "Word not found to delete!" << endl;
    }

    // Display function
    void display() {
        cout << "\nDictionary contents:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";
            for (auto entry : table[i]) {
                cout << "(" << entry.word << " : "
                     << entry.meaning << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Dictionary dict;

    dict.insert("apple", "a fruit");
    dict.insert("ball", "a round object");
    dict.insert("cat", "a small animal");
    dict.insert("dog", "a loyal animal");

    dict.display();

    dict.search("cat");
    dict.search("zebra");

    dict.remove("ball");

    dict.display();

    return 0;
}
