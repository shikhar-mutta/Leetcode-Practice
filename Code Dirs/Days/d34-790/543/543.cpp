// Link: https://leetcode.com/problems/diameter-of-binary-tree/description/

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

// TC: O(n), SC: O(h) where h is the height of the tree. In worst case, h = n.
class Solution
{
public:
    int best = 0;
    // Returns height; updates best with the longest path (in edges) through this node.
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        best = max(best, l + r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        best = 0;
        height(root);
        return best;
    }
};
