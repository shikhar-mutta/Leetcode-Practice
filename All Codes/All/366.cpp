// Link: https://leetcode.com/problems/find-leaves-of-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n)  SC: O(n)
// Approach: compute each node's height (leaves = height 0), group node
// values by height into buckets, return buckets in order
class Solution {
    int height(TreeNode* node, vector<vector<int>>& res) {
        if (!node) return -1;
        int lh = height(node->left, res);
        int rh = height(node->right, res);
        int h = 1 + max(lh, rh);
        if ((int)res.size() <= h) res.resize(h + 1);
        res[h].push_back(node->val);
        return h;
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        height(root, res);
        return res;
    }
};
