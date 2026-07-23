// Link: https://leetcode.com/problems/range-sum-of-bst/description/

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

// TC: O(n), where n is the number of nodes in the tree.
// SC: O(h), where h is the height of the tree.
// Approach:
// 1. We will check if the root is null, if yes then return 0.
// 2. If the value of the root is less than low, then we will only check the right subtree.
// 3. If the value of the root is greater than high, then we will only check the left subtree.
// 4. If the value of the root is in the range [low, high], then we will add the value of the root to the sum of the left and right subtrees.
// 5. Finally, we will return the sum of the values in the range [low, high].
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
