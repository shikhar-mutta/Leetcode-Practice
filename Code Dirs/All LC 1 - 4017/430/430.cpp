// Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// TC: O(n)  SC: O(depth) recursion
// Approach: DFS - whenever a node has a child, recursively flatten the
// child list, splice it in between the node and its next, then continue
class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur) {
            if (cur->child) {
                Node* next = cur->next;
                Node* childHead = flatten(cur->child);
                cur->next = childHead;
                childHead->prev = cur;
                cur->child = nullptr;

                Node* tail = childHead;
                while (tail->next) tail = tail->next;
                tail->next = next;
                if (next) next->prev = tail;
            }
            cur = cur->next;
        }
        return head;
    }
};
