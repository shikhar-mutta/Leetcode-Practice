// Link: https://leetcode.com/problems/path-sum-ii/description/

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
// Approach: backtracking DFS carrying the running path and remaining sum, collect at every qualifying leaf
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* node, int remain) {
            if (!node) return;
            path.push_back(node->val);
            remain -= node->val;
            if (!node->left && !node->right && remain == 0) res.push_back(path);
            dfs(node->left, remain);
            dfs(node->right, remain);
            path.pop_back();
        };
        dfs(root, targetSum);
        return res;
    }
};
