// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};

// TC: O(n) SC: O(n)
// Approach: recursive preorder — visit node, then recurse into each child in order.
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(Node* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        for (auto* c : node->children) dfs(c, res);
    }
};
