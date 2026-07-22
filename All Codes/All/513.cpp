// Link: https://leetcode.com/problems/find-bottom-left-tree-value/description/

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

// TC: O(n) where n is the number of nodes in the tree
// SC: O(n) where n is the number of nodes in the tree
// Approach:
//  1. Use a queue to perform a level order traversal of the tree.
//  2. For each level, store the value of the first node (leftmost node) in the answer variable.
//  3. Continue this process until all levels are traversed, and the answer variable will contain the value of the bottom-left node.
//  4. Return the answer variable.
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int ans = root->val;
        while (!q.empty())
        {
            int sz = q.size();
            ans = q.front()->val;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
