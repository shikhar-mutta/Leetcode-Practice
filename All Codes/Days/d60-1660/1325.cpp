// Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

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
    // TC: O(N) SC: O(H)
    //  Approach:
    //   1. We can use a recursive approach to solve this problem. We can start from the root of the tree and check if the current node is a leaf node and has the target value. If it does, we can delete it by returning nullptr.
    //   2. If the current node is not a leaf node, we can recursively call the function on its left and right children.
    //   3. After the recursive calls, we can check if the current node is a leaf node and has the target value. If it does, we can delete it by returning nullptr. Otherwise, we can return the current node.
    //   4. This process will continue until we have checked all the nodes in the tree and deleted all the leaf nodes with the target value.
    //   5. The function will return the modified tree with the leaf nodes with the target value deleted.
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (!root)
            return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (!root->left && !root->right && root->val == target)
            return nullptr;
        return root;
    }
};
