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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxSumBST(TreeNode *root)
    {
        int best = 0;
        dfs(root, best);
        return best;
    }

private:
    struct Info
    {
        bool isBST;
        int minVal, maxVal, sum;
    };

    Info dfs(TreeNode *node, int &best)
    {
        if (!node)
            return {true, INT_MAX, INT_MIN, 0};
        Info left = dfs(node->left, best);
        Info right = dfs(node->right, best);
        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal)
        {
            int sum = left.sum + right.sum + node->val;
            best = max(best, sum);
            // missing semicolon here was a syntax error
            return { true, min(node->val, left.minVal), max(node->val, right.maxVal), sum };
        }
        return {false, 0, 0, 0};
    };
};