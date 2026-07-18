// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // TC: O(h). SC: O(1).
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root && root->val != val)
            root = val < root->val ? root->left : root->right;
        return root;
    }
};
