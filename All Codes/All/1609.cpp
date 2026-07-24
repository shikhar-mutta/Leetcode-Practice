// Link: https://leetcode.com/problems/even-odd-tree/description/

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

// TC: O(n) SC: O(n)
// Approach:
//  1. We will do a level order traversal of the tree.
//  2. For each level, we will check if the values are in the correct order
//     and if they are even or odd based on the level index.
class Solution
{
public:
    bool isEven(int num) { return (num % 2 == 0); }
    bool isEvenOddTree(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        bool isEvenIndex = true;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int mini = INT_MIN;
            int maxi = INT_MAX;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (isEvenIndex)
                {
                    if (isEven(node->val) || mini >= node->val)
                    {
                        return false;
                    }
                    mini = node->val;
                }
                else
                {
                    if (!isEven(node->val) || maxi <= node->val)
                    {
                        return false;
                    }
                    maxi = node->val;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            isEvenIndex = !isEvenIndex;
        }
        return true;
    }
};