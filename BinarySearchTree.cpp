#include <iostream>
using namespace std;

// Time Complexity:
// Insert at beginning: O(1)
// Delete: O(n)
// Search: O(n)

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void search(int key) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << key << " Found\n";
                return;
            }
            temp = temp->next;
        }

        cout << key << " Not Found\n";
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Element not found\n";
            return;
        }

        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Linked List: ";
    list.display();

    list.search(20);

    list.deleteNode(20);

    cout << "After Deletion: ";
    list.display();

    return 0;
}
