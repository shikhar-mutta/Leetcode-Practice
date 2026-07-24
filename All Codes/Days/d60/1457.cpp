// Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/

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

// TC: O(n), SC: O(h) where n is the number of nodes in the tree and h is the height of the tree
// Approach:
//  1. Use a depth-first search (DFS) approach to traverse the binary tree.
//  2. Maintain a bitmask to keep track of the parity (even or odd) of the counts of the digits along the current path from the root to the current node.
//  3. At each node, update the bitmask by toggling the bit corresponding to the current node's value.
//  4. When reaching a leaf node, check if the bitmask has at most one bit set (i.e., the number of digits with odd counts is at most one). This can be done by checking if mask & (mask - 1) == 0, which indicates that the path can form a pseudo-palindrome.
//  5. Return the total count of pseudo-palindromic paths found during the traversal.
class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root) { return dfs(root, 0); }

private:
    int dfs(TreeNode *node, int mask)
    {
        if (!node)
            return 0;
        mask ^= 1 << node->val;
        if (!node->left && !node->right)
            return (mask & (mask - 1)) == 0 ? 1 : 0;
        return dfs(node->left, mask) + dfs(node->right, mask);
    }
};