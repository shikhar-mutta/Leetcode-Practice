// Link: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node() {}
    Node(int _val) { val = _val; next = nullptr; }
    Node(int _val, Node* _next) { val = _val; next = _next; }
};

// TC: O(n) SC: O(1)
// Approach: if list empty, create single self-looping node. Otherwise walk the ring looking for a valid insertion point: normal ascending gap, or the max->min wrap point if no normal gap fits; if we loop all the way back without finding a spot (uniform list), insert anywhere.
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }
        Node* cur = head;
        while (true) {
            if (cur->val <= insertVal && insertVal <= cur->next->val) break;
            if (cur->val > cur->next->val) {
                if (insertVal >= cur->val || insertVal <= cur->next->val) break;
            }
            cur = cur->next;
            if (cur == head) break;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        return head;
    }
};
