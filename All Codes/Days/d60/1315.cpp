// Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/

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

// TC: O(n) SC: O(h) where h is the height of the tree
// Approach:
//  1. We can use a depth-first search (DFS) approach to traverse the binary tree. We can keep track of the parent and grandparent values as we traverse the tree. If the grandparent value is even, we can add the current node's value to the sum. We can recursively call the DFS function for the left and right children of the current node, passing the current node's value as the parent and the parent's value as the grandparent. Finally, we can return the total sum of all nodes with even-valued grandparents.
//  2. The base case for the recursion is when the current node is null, in which case we return 0.
class Solution
{
public:
    int sumEvenGrandparent(TreeNode *root) { return dfs(root, 1, 1); }

private:
    int dfs(TreeNode *node, int parent, int grandparent)
    {
        if (!node)
            return 0;
        int sum = (grandparent % 2 == 0) ? node->val : 0;
        return sum + dfs(node->left, node->val, parent) +
               dfs(node->right, node->val, parent);
    }
};
