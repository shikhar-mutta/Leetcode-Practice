// Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

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

// TC: O(n)
// SC: O(h) where h is the height of the tree
// Approach:
// 1. We can use DFS to traverse the tree and calculate the number of moves required to distribute the coins.
// 2. For each node, we calculate the number of coins that need to be moved to or from its left and right children.
// 3. The number of moves required for a node is the sum of the absolute values of the coins that need to be moved to or from its left and right children.
class Solution
{
    int moves = 0;
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        moves += abs(left) + abs(right);
        return node->val + left + right - 1;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        moves = 0;
        dfs(root);
        return moves;
    }
};
