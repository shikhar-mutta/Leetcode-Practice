// Link: https://leetcode.com/problems/print-binary-tree/description/

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

// TC: O(2^h) SC: O(2^h)
// Approach: compute tree height, allocate a grid of width 2^h-1, recursively place each node's value at the midpoint of its column range.
class Solution {
    int height(TreeNode* node) {
        if (!node) return -1;
        return 1 + max(height(node->left), height(node->right));
    }
    void fill(TreeNode* node, vector<vector<string>>& grid, int row, int lo, int hi) {
        if (!node) return;
        int mid = (lo + hi) / 2;
        grid[row][mid] = to_string(node->val);
        fill(node->left, grid, row+1, lo, mid-1);
        fill(node->right, grid, row+1, mid+1, hi);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int rows = h+1;
        int cols = (1 << (h+1)) - 1;
        vector<vector<string>> grid(rows, vector<string>(cols, ""));
        fill(root, grid, 0, 0, cols-1);
        return grid;
    }
};
