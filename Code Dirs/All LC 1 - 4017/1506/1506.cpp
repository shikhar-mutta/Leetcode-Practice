// Link: https://leetcode.com/problems/find-root-of-n-ary-tree/description/

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
    Node* findRoot(vector<Node*> tree) {
        long long xorAll = 0;
        for (Node* node : tree) {
            xorAll ^= node->val;
            for (Node* child : node->children) xorAll ^= child->val;
        }
        for (Node* node : tree) if (node->val == xorAll) return node;
        return nullptr;
    }
};
