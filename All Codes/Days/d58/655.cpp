// Link: https://leetcode.com/problems/print-binary-tree/description/

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
    //  Approach:
    //   1. Calculate the height of the binary tree using a recursive function.
    //   2. Calculate the number of rows and columns for the output matrix based on the height of the tree.
    //   3. Create a 2D vector of strings with the calculated number of rows and columns, initialized with empty strings.
    //   4. Use a recursive function to fill the output matrix with the values of the tree nodes, placing them in the correct positions based on their row and column indices.
    //   5. Return the filled output matrix.
    int height(TreeNode *root)
    {
        if (!root)
            return -1;
        return 1 + max(height(root->left), height(root->right));
    }

    void fill(TreeNode *node, int r, int c, int h, vector<vector<string>> &res)
    {
        if (!node)
            return;
        res[r][c] = to_string(node->val);
        if (r == h)
            return; // bottom row: no children to place
        int offset = 1 << (h - r - 1);
        fill(node->left, r + 1, c - offset, h, res);
        fill(node->right, r + 1, c + offset, h, res);
    }

    vector<vector<string>> printTree(TreeNode *root)
    {
        int h = height(root);
        int rows = h + 1;
        int cols = (1 << (h + 1)) - 1;
        vector<vector<string>> res(rows, vector<string>(cols, ""));
        fill(root, 0, (cols - 1) / 2, h, res);
        return res;
    }
};