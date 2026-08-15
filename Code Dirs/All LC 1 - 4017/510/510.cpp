// Link: https://leetcode.com/problems/inorder-successor-in-bst-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

// TC: O(h)  SC: O(1)
// Approach: if node has a right subtree, successor is its leftmost node;
// otherwise walk up until we move up from a left child
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            Node* cur = node->right;
            while (cur->left) cur = cur->left;
            return cur;
        }
        Node* cur = node;
        while (cur->parent && cur->parent->right == cur) cur = cur->parent;
        return cur->parent;
    }
};
