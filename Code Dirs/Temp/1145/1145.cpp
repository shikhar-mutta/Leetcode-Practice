// Link: https://leetcode.com/problems/binary-tree-coloring-game/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int leftCount = 0, rightCount = 0, x;

    int count(TreeNode *node)
    {
        if (!node)
            return 0;
        int l = count(node->left);
        int r = count(node->right);
        if (node->val == x)
        {
            leftCount = l;
            rightCount = r;
        }
        return l + r + 1;
    }

public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        this->x = x;
        count(root);
        int parentSide = n - leftCount - rightCount - 1;
        int half = n / 2;
        return max({leftCount, rightCount, parentSide}) > half;
    }
};