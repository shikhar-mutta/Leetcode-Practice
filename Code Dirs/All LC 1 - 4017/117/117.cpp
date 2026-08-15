// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// TC: O(n)  SC: O(1)
// Approach: general (not-necessarily-perfect) binary tree; use a dummy node to build the next level's
// linked list while walking the current level via established next pointers
class Solution {
public:
    Node* connect(Node* root) {
        Node* levelStart = root;
        while (levelStart) {
            Node dummy(0);
            Node* tail = &dummy;
            Node* cur = levelStart;
            while (cur) {
                if (cur->left) { tail->next = cur->left; tail = tail->next; }
                if (cur->right) { tail->next = cur->right; tail = tail->next; }
                cur = cur->next;
            }
            levelStart = dummy.next;
        }
        return root;
    }
};
