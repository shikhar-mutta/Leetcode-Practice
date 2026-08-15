// Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

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

// TC: O(n)  SC: O(h)
// Approach: DFS, depth = 1 + max depth of children
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int best = 0;
        for (auto* c : root->children) best = max(best, maxDepth(c));
        return 1 + best;
    }
};
