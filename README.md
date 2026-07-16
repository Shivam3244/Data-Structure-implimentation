# Data Structures in C++

## Overview
This project implements two fundamental data structures from scratch using C++.

### Implemented Data Structures
- Linked List
- Binary Search Tree (BST)

Each implementation includes:
- Insert operation
- Search operation
- Delete operation
- Driver program for testing
- Time complexity comments

---

## Compilation

### Linked List

g++ LinkedList.cpp -o linkedlist
./linkedlist

### Binary Search Tree

g++ BinarySearchTree.cpp -o bst
./bst

---

## Sample Output

### Linked List

Linked List: 10 20 30
20 Found
After Deletion: 10 30

### Binary Search Tree

BST (Inorder): 20 30 40 50 70
40 Found
After Deletion: 20 40 50 70

---

## Complexity Analysis

### Linked List

| Operation | Complexity |
|-----------|------------|
| Insert | O(n) |
| Search | O(n) |
| Delete | O(n) |

### Binary Search Tree (Average)

| Operation | Complexity |
|-----------|------------|
| Insert | O(log n) |
| Search | O(log n) |
| Delete | O(log n) |

Worst Case: O(n)
