// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int best = 0;
        // BFS, numbering nodes by position; normalize per level to avoid overflow.
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int n = q.size();
            unsigned long long base = q.front().second, first = 0, last = 0;
            for (int i = 0; i < n; i++)
            {
                auto [cur, idx] = q.front();
                q.pop();
                idx -= base;
                if (i == 0)
                    first = idx;
                if (i == n - 1)
                    last = idx;
                if (cur->left)
                    q.push({cur->left, idx * 2});
                if (cur->right)
                    q.push({cur->right, idx * 2 + 1});
            }
            best = max(best, (int)(last - first + 1));
        }
        return best;
    }
};
