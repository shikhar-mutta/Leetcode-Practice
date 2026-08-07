// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

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
// Approach: perfect binary tree, so use already-established next pointers at the current level
// to walk across and link the next level's children without a queue
class Solution {
public:
    Node* connect(Node* root) {
        Node* leftmost = root;
        while (leftmost && leftmost->left) {
            Node* cur = leftmost;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
