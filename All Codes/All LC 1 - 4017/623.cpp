// Link: https://leetcode.com/problems/add-one-row-to-tree/description/

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

// TC: O(n), where n is the number of nodes in the tree. We visit each node once to insert the new row, so the time complexity is linear in the number of nodes.
// SC: O(h), where h is the height of the tree. The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the tree.
// Approach:
// 1. If the depth is 1, create a new root node with the given value and set the original root as its left child.
// 2. Otherwise, recursively traverse the tree until reaching the desired depth - 1.
class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            return new TreeNode(val, root, nullptr);
        }
        insert(root, val, depth, 1);
        return root;
    }

    void insert(TreeNode *node, int val, int depth, int curDepth)
    {
        if (!node)
            return;
        if (curDepth == depth - 1)
        {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
        else
        {
            insert(node->left, val, depth, curDepth + 1);
            insert(node->right, val, depth, curDepth + 1);
        }
    }
};
