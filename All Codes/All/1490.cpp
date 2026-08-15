// Link: https://leetcode.com/problems/clone-n-ary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        Node* copy = new Node(root->val);
        for (Node* child : root->children) {
            copy->children.push_back(cloneTree(child));
        }
        return copy;
    }
};
