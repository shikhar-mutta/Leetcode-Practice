// Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/

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

// TC: O(n) SC: O(h) where n is the number of nodes in the tree and h is the height of the tree
//  Approach: DFS
//  1. Use DFS to traverse the tree and keep track of the current value of the path from root to leaf.
//  2. When a leaf node is reached, add the current value to the sum.
//  3. Return the sum after traversing the entire tree.
class Solution
{
public:
    void dfs(TreeNode *node, int cur, int &sum)
    {
        if (!node)
            return;
        cur = cur * 2 + node->val;
        if (!node->left && !node->right)
        {
            sum += cur;
            return;
        }
        dfs(node->left, cur, sum);
        dfs(node->right, cur, sum);
    }

    int sumRootToLeaf(TreeNode *root)
    {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};
