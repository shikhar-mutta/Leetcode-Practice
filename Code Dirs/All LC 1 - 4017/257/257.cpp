// Link: https://leetcode.com/problems/binary-tree-paths/description/

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

// TC: O(n^2) worst case (string building)  SC: O(n)
// Approach: DFS building the "val->val->..." path string, collect at each leaf
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        function<void(TreeNode*,string)> dfs = [&](TreeNode* node, string path) {
            path += to_string(node->val);
            if (!node->left && !node->right) { res.push_back(path); return; }
            if (node->left) dfs(node->left, path + "->");
            if (node->right) dfs(node->right, path + "->");
        };
        dfs(root, "");
        return res;
    }
};
