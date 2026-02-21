#include <iostream>
using namespace std;

class hello {
public:
    int data;
    hello* left;
    hello* right;

    hello(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

hello* insertNode(hello* root, int value) {
    if (root == NULL) {
        return new hello(value);
    }

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

bool searchNode(hello* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;

    if (key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

hello* findMin(hello* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL) return root;
    return findMin(root->left);
}

hello* findMax(hello* root) {
    if (root == NULL) return NULL;
    if (root->right == NULL) return root;
    return findMax(root->right);
}

hello* deleteNode(hello* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            hello* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            hello* temp = root->left;
            delete root;
            return temp;
        }

        hello* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(hello* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(hello* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(hello* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    
}

int main() {
    hello* root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "inorder traversal: "<<endl;
    inorder(root);

    cout << "preorder traversal: "<<endl;
    preorder(root);

    cout << "postorder traversal: "<<endl;
    postorder(root);

    cout << "Searching " << searchNode(root, 40) << " Found" <<endl;

    cout << "Minimum : " << findMin(root)->data<<endl;
    cout << "Maximum : " << findMax(root)->data<<endl;

    root = deleteNode(root, 70);

    cout << "after delete the 70, inorder: "<<endl;
    inorder(root);

    cout << endl;
    return 0;
}
