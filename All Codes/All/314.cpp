// Link: https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/

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

// TC: O(n log n)  SC: O(n)
// Approach: BFS tracking column index per node, group values by column,
// then output columns left to right (top-to-bottom, left-to-right within a column by BFS order)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int, vector<int>> cols;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, col] = q.front(); q.pop();
            cols[col].push_back(node->val);
            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }
        for (auto& [col, vals] : cols) res.push_back(vals);
        return res;
    }
};
