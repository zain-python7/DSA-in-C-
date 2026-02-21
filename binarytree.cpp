#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class Meow {
public:
    Node* root;

    Meow() { root = NULL; }

    Node* insert(Node* node, int value) {
        if (node == NULL) return new Node(value);
        if (value < node->data) node->left = insert(node->left, value);
        else node->right = insert(node->right, value);
        return node;
    }

    void insert(int value) { root = insert(root, value); }

    void inorder(Node* node) {
        stack<Node*> s;
        Node* current = node;
        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            current = s.top(); s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            Node* current = s.top(); s.pop();
            cout << current->data << " ";
            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
    }

    // Postorder using ONE stack
    void postorder1(Node* node) {
        if (node == NULL) return;
        stack<Node*> s;
        Node* current = node;
        Node* lastVisited = NULL;

        while (!s.empty() || current != NULL) {
            if (current != NULL) {
                s.push(current);
                current = current->left;
            } else {
                Node* peekNode = s.top();
                if (peekNode->right != NULL && lastVisited != peekNode->right)
                    current = peekNode->right;
                else {
                    cout << peekNode->data << " ";
                    lastVisited = peekNode;
                    s.pop();
                }
            }
        }
    }

    //  Postorder using TWO stacks
    void postorder2(Node* node) {
        if (node == NULL) return;

        stack<Node*> s1, s2;
        s1.push(node);

        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }
};

int main() {
    Meow tree;
    tree.insert(8);
    tree.insert(10);
    tree.insert(3);
    tree.insert(6);
    tree.insert(1);
    tree.insert(4);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder (one stack): ";
    tree.postorder1(tree.root);
    cout << endl;

    cout << "Postorder (two stacks): ";
    tree.postorder2(tree.root);
    cout << endl;

    return 0;
}
