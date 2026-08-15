// Link: https://leetcode.com/problems/binary-tree-coloring-game/description/

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

// TC: O(n) where n is the number of nodes in the binary tree
// SC: O(h) where h is the height of the binary tree for the recursion stack
//   Approach:
//    1. Use a recursive function to count the number of nodes in the left and right subtrees of the node with value x.
//    2. Calculate the number of nodes in the parent side as n - leftCount - rightCount - 1.
//    3. Check if any of the three sides (left subtree, right subtree, parent side) has more than half of the total nodes. If so, return true as the second player can win by choosing that side. Otherwise, return false.
class Solution
{
    int leftCount = 0, rightCount = 0, x;

    int count(TreeNode *node)
    {
        if (!node)
            return 0;
        int l = count(node->left);
        int r = count(node->right);
        if (node->val == x)
        {
            leftCount = l;
            rightCount = r;
        }
        return l + r + 1;
    }

public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        this->x = x;
        count(root);
        int parentSide = n - leftCount - rightCount - 1;
        int half = n / 2;
        return max({leftCount, rightCount, parentSide}) > half;
    }
};