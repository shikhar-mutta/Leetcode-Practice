// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    // TC: O(n), SC: O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                int idx = leftToRight ? i : n - 1 - i;
                level[idx] = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }
};
