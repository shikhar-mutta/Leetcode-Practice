// Link: https://leetcode.com/problems/binary-tree-paths/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        function<void(TreeNode*, string)> dfs = [&](TreeNode* node, string path) {
            if (!node->left && !node->right) { ans.push_back(path); return; }
            if (node->left)  dfs(node->left,  path + "->" + to_string(node->left->val));
            if (node->right) dfs(node->right, path + "->" + to_string(node->right->val));
        };
        if (root) dfs(root, to_string(root->val));
        return ans;
    }
};
