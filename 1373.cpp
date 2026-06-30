// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// TC: O(n), SC: O(h)
class Solution
{
    struct Info
    {
        bool isBST;
        int mn, mx;
        int sum;
    };
    int ans = 0;
    // Post-order: a node forms a BST iff both children do and its value
    // sits between the left subtree's max and the right subtree's min.
    Info dfs(TreeNode *node)
    {
        if (!node)
            return {true, INT_MAX, INT_MIN, 0};
        Info l = dfs(node->left), r = dfs(node->right);
        if (l.isBST && r.isBST && node->val > l.mx && node->val < r.mn)
        {
            int s = l.sum + r.sum + node->val;
            ans = max(ans, s);
            return {true, min(l.mn, node->val), max(r.mx, node->val), s};
        }
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode *root)
    {
        ans = 0;
        dfs(root);
        return ans;
    }
};
