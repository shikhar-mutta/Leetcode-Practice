// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        flatten(root->left);  // Flatten left subtree
        flatten(root->right); // Flatten right subtree

        TreeNode *temp = root->right; // Store the right subtree
        root->right = root->left;     // Move left subtree to the right
        root->left = nullptr;         // Set left child to null

        TreeNode *current = root;
        while (current->right) // Traverse to the end of the new right subtree
            current = current->right;

        current->right = temp; // Attach the original right subtree
    }
};
