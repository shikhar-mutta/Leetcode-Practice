// Link: https://leetcode.com/problems/root-equals-sum-of-children/description/

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

// TC: O(1), SC: O(1)
//  Approach:
//  1. We can simply check if the value of the root node is equal to the sum of the values of its left and right children.
//  2. If it is, we return true, otherwise we return false.
class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        return root->val == root->left->val + root->right->val;
    }
};