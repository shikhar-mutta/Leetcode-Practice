// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes; // col, row, val
        function<void(TreeNode*,int,int)> dfs = [&](TreeNode* node, int col, int row) {
            if (!node) return;
            nodes.push_back({col, row, node->val});
            dfs(node->left, col-1, row+1);
            dfs(node->right, col+1, row+1);
        };
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prevCol = INT_MIN;
        for (auto& [col, row, val] : nodes) {
            if (col != prevCol) { res.push_back({}); prevCol = col; }
            res.back().push_back(val);
        }
        return res;
    }
};
