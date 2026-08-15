// Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

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

// TC: O(n) where n is the number of nodes in the BST
// SC: O(n) where n is the number of nodes in the BST
// Approach:
//  1. Perform an in-order traversal of the BST to get the values in sorted order
//  2. Keep track of the current value and its count, as well as the maximum count seen so far
//  3. If the current value's count exceeds the maximum count, update the maximum count and clear the modes vector, adding the current value to it
//  4. If the current value's count equals the maximum count, add the current value to the modes vector
class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> modes;
        TreeNode *prev = nullptr;
        int curCount = 0, maxCount = 0;
        inorder(root, prev, curCount, maxCount, modes);
        return modes;
    }

private:
    void inorder(TreeNode *node, TreeNode *&prev, int &curCount, int &maxCount, vector<int> &modes)
    {
        if (!node)
            return;
        inorder(node->left, prev, curCount, maxCount, modes);

        if (prev && prev->val == node->val)
            curCount++;
        else
            curCount = 1;

        if (curCount > maxCount)
        {
            maxCount = curCount;
            modes.clear();
            modes.push_back(node->val);
        }
        else if (curCount == maxCount)
        {
            modes.push_back(node->val);
        }
        prev = node;

        inorder(node->right, prev, curCount, maxCount, modes);
    }
};
