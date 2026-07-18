// Link: https://leetcode.com/problems/design-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
    struct Node { int val; Node* next; Node(int v) : val(v), next(nullptr) {} };
    Node* head;
    int sz;
public:
    MyLinkedList() : head(nullptr), sz(0) {}

    int get(int index) {
        if (index < 0 || index >= sz) return -1;
        Node* cur = head;
        while (index--) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }
    void addAtTail(int val) { addAtIndex(sz, val); }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz) return;
        Node* node = new Node(val);
        if (index == 0) {
            node->next = head;
            head = node;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) cur = cur->next;
            node->next = cur->next;
            cur->next = node;
        }
        sz++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz) return;
        Node* del;
        if (index == 0) {
            del = head;
            head = head->next;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) cur = cur->next;
            del = cur->next;
            cur->next = del->next;
        }
        delete del;
        sz--;
    }
};
