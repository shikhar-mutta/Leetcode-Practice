// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int best = INT_MIN;
    // Returns the max path sum starting at root and going down one side.
    int gain(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = max(0, gain(root->left));
        int r = max(0, gain(root->right));
        best = max(best, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root)
    {
        best = INT_MIN;
        gain(root);
        return best;
    }
};
