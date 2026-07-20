// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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

// TC: O(n) where n is the number of nodes in the tree. We visit each node exactly once during the depth-first search (DFS) traversal.
// SC: O(h) where h is the height of the tree. The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the tree.
// Approach:
//  1. We perform a depth-first search (DFS) traversal of the binary tree, keeping track of the current number formed by the path from the root to the current node.
//  2. At each node, we update the current number by multiplying the previous number by 10 and adding the value of the current node.
//  3. When we reach a leaf node (a node with no children), we add the current number to the total sum.
//  4. We return the total sum after traversing all paths from the root to the leaf nodes.

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        function<int(TreeNode *, int)> dfs = [&](TreeNode *node,
                                                 int cur) -> int
        {
            if (!node)
                return 0;
            cur = cur * 10 + node->val;
            if (!node->left && !node->right)
                return cur;
            return dfs(node->left, cur) + dfs(node->right, cur);
        };
        return dfs(root, 0);
    }
};
