// Link: https://leetcode.com/problems/convert-bst-to-greater-tree/description/

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
//   1. We will do a reverse inorder traversal of the tree (right -> root -> left) to visit the nodes in decreasing order of their values.
//   2. We will maintain a running sum of the values of the nodes we have visited so far.
//   3. For each node, we will update its value to be the running sum and then add its original value to the running sum.
//   4. Finally, we will return the root of the modified tree
class Solution
{
public:
    int sum = 0;

    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};
