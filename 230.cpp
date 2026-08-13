// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int ans = 0;

    void inorder(TreeNode *root, int k)
    {
        if (!root || count >= k)
            return;
        inorder(root->left, k);
        if (--k == 0)
        {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return ans;
    }
};
