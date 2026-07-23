// Link: https://leetcode.com/problems/univalued-binary-tree/description/

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

class Solution
{
public:
    // TC: O(n), SC: O(h)
    //  Approach: Recursion
    //  1. We will check if the left and right child of the current node are equal to the current node's value
    //  2. If they are not equal, we will return false
    //  3. If they are equal, we will recursively check the left and right subtrees
    //  4. If both subtrees are univalued, we will return true
    //  5. If either subtree is not univalued, we will return false
    //  6. If the current node is null, we will return true
    //  7. If the current node is a leaf node, we will return true
    //  8. If the current node has only one child, we will check if the child is equal to the current node's value
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
            return true;
        if (root->left && root->left->val != root->val)
            return false;
        if (root->right && root->right->val != root->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
