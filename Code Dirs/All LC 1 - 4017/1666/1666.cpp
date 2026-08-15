// Link: https://leetcode.com/problems/change-the-root-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* flipBinaryTree(Node* root, Node* leaf) {
        vector<Node*> path;
        Node* cur = leaf;
        while (cur) { path.push_back(cur); cur = cur->parent; }

        for (size_t i = 0; i + 1 < path.size(); i++) {
            Node* child = path[i];
            Node* parent = path[i + 1];
            if (parent->left == child) parent->left = nullptr;
            else parent->right = nullptr;
            if (child->left == nullptr) child->left = parent;
            else child->right = parent;
            parent->parent = child;
        }
        leaf->parent = nullptr;
        return leaf;
    }
};
