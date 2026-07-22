// Link: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

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

// TC: O(n) where n is the number of nodes in the tree, as we may need to visit all nodes in the worst case.
// SC: O(h) where h is the height of the tree, which is the space used by the recursion stack. In the worst case, the height of the tree can be n (for a skewed tree), but for a balanced tree, it would be log(n).
//   Approach:
//   1. We perform a depth-first search (DFS) on the binary tree.
//   2. We keep track of the root value and look for the smallest value that is greater than the root value.
//   3. If we find a node with a value greater than the root value, we check if it's smaller than the current result. If it is, we update the result.
//   4. We continue the search until all nodes are visited, and finally return the result, which will be the second minimum value in the tree or -1 if it doesn't exist.
//   5. The DFS function is called recursively for the left and right children of each node.
//   6. The result is initialized to -1, and if we find a valid second minimum value, we update it accordingly.
class Solution
{
public:
    long long result;
    long long rootVal;

    int findSecondMinimumValue(TreeNode *root)
    {
        result = -1;
        rootVal = root->val;
        dfs(root);
        return (int)result;
    }

    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        if (node->val != rootVal)
        {
            if (result == -1 || node->val < result)
                result = node->val;
            return;
        }
        dfs(node->left);
        dfs(node->right);
    }
};
