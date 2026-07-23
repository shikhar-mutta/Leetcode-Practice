// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

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
    //  Approach: Level Order Traversal (BFS)
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool seenNull = false;
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (!cur)
            {
                seenNull = true;
                continue;
            }
            if (seenNull)
                return false;
            q.push(cur->left);
            q.push(cur->right);
        }
        return true;
    }
};
