// Link: https://leetcode.com/problems/sum-of-left-leaves/description/

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

// TC: O(n), SC: O(h) where h is the height of the tree
//  Approach:
//   1. Use a depth-first search (DFS) approach to traverse the binary tree
//   2. Keep track of whether the current node is a left child or not
//   3. If the current node is a leaf node and is a left child, add its value to the sum
//   4. Recursively call the DFS function for the left and right children of the current node, passing the appropriate isLeft flag
//   5. Return the total sum of left leaves found during the traversal
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return dfs(root, false);
    }

private:
    int dfs(TreeNode *node, bool isLeft)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return isLeft ? node->val : 0;
        return dfs(node->left, true) + dfs(node->right, false);
    }
};
