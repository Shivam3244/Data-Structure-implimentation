#include <iostream>
using namespace std;

// Time Complexity:
// Insert: O(log n) Average, O(n) Worst
// Search: O(log n) Average, O(n) Worst
// Delete: O(log n) Average, O(n) Worst

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {

public:
    Node* insert(Node* root, int key) {

        if (root == NULL)
            return new Node(key);

        if (key < root->data)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);

        return root;
    }

    bool search(Node* root, int key) {

        if (root == NULL)
            return false;

        if (root->data == key)
            return true;

        if (key < root->data)
            return search(root->left, key);

        return search(root->right, key);
    }

    Node* minValue(Node* node) {
        Node* current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    Node* deleteNode(Node* root, int key) {

        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        else {

            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValue(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    void inorder(Node* root) {

        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {

    BST tree;
    Node* root = NULL;

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);

    cout << "Inorder Traversal: ";
    tree.inorder(root);

    cout << endl;

    if (tree.search(root, 40))
        cout << "40 Found\n";
    else
        cout << "40 Not Found\n";

    root = tree.deleteNode(root, 30);

    cout << "After Deletion: ";
    tree.inorder(root);

    return 0;
}
