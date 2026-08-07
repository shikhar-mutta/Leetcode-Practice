// Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

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

// TC: O(n)  SC: O(n)
// Approach: standard BFS level order traversal
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; i++) {
                Node* node = q.front(); q.pop();
                level.push_back(node->val);
                for (auto* c : node->children) q.push(c);
            }
            res.push_back(level);
        }
        return res;
    }
};
