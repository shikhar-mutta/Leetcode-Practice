// Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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

// TC: O(n) SC: O(h)
// Approach: DFS
//  1. We can use a depth-first search (DFS) approach to traverse the binary tree and keep track of the minimum and maximum values encountered along the path from the root to the current node.
//  2. At each node, we calculate the absolute difference between the current node's value and the minimum and maximum values encountered so far. We update the best difference found so far if the current difference is greater than the previous best.
//  3. We then recursively call the DFS function for the left and right child nodes, passing along the updated minimum and maximum values.
//  4. Finally, we return the best difference found after traversing the entire tree.
class Solution
{
public:
    void dfs(TreeNode *node, int curMin, int curMax, int &best)
    {
        if (!node)
            return;
        best = max({best, abs(node->val - curMin), abs(node->val - curMax)});
        curMin = min(curMin, node->val);
        curMax = max(curMax, node->val);
        dfs(node->left, curMin, curMax, best);
        dfs(node->right, curMin, curMax, best);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        int best = 0;
        dfs(root, root->val, root->val, best);
        return best;
    }
};
