// Link: https://leetcode.com/problems/design-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(index) per op SC: O(n)
// Approach: singly linked list with a dummy head; traverse to the target index for each operation.
class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    Node* dummy;
    int size;
public:
    MyLinkedList() { dummy = new Node(0); size = 0; }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* cur = dummy->next;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(size, val); }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        Node* prev = dummy;
        for (int i = 0; i < index; i++) prev = prev->next;
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* prev = dummy;
        for (int i = 0; i < index; i++) prev = prev->next;
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
    }
};
