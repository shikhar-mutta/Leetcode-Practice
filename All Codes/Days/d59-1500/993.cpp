// Link: https://leetcode.com/problems/cousins-in-binary-tree/description/

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
    // TC: O(n) where n is the number of nodes in the tree.
    // SC: O(n) where n is the number of nodes in the tree.
    // Approach:
    //  1. We will use a queue to perform a level order traversal of the tree.
    //  2. For each level, we will check if both x and y are present in the current level. If they are, we will check if they have different parents. If they do, we will return true. If they have the same parent, we will return false. If only one of them is present in the current level, we will return false. If neither of them is present in the current level, we will continue to the next level.
    //  3. If we reach the end of the tree without finding both x and y, we will return false.
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root, nullptr});
        while (!q.empty())
        {
            int size = q.size();
            TreeNode *parentX = nullptr;
            TreeNode *parentY = nullptr;
            for (int i = 0; i < size; i++)
            {
                auto [node, parent] = q.front();
                q.pop();
                if (node->val == x)
                    parentX = parent;
                if (node->val == y)
                    parentY = parent;
                if (node->left)
                    q.push({node->left, node});
                if (node->right)
                    q.push({node->right, node});
            }
            if (parentX && parentY)
                return parentX != parentY;
            if (parentX || parentY)
                return false;
        }
        return false;
    }
};
