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
        if (!root)
            return ans;
        queue<pair<TreeNode *, string>> q;
        q.push({root, to_string(root->val)});
        while (!q.empty())
        {
            auto [node, path] = q.front();
            q.pop();
            if (!node->left && !node->right)
                ans.push_back(path);
            if (node->left)
                q.push({node->left, path + "->" + to_string(node->left->val)});
            if (node->right)
                q.push({node->right, path + "->" + to_string(node->right->val)});
        }
        return ans;
    }
};
