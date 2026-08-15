// Link: https://leetcode.com/problems/validate-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    // TC: O(n), SC: O(h) for recursion stack.
public:
    bool isValidBST(TreeNode *root)
    {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }

private:
    // Every node must lie strictly within (lo, hi); bounds tighten on descent.
    bool valid(TreeNode *node, long long lo, long long hi)
    {
        if (!node)
            return true;
        if (node->val <= lo || node->val >= hi)
            return false;
        return valid(node->left, lo, node->val) && valid(node->right, node->val, hi);
    }
};
