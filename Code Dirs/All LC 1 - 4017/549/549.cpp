// Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/

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

// TC: O(n)  SC: O(h)
// Approach: postorder returning (longest increasing chain down, longest
// decreasing chain down) from each node; combine child chains through the
// node if values connect consecutively, track global max
class Solution {
    int best = 0;

    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        int inc = 1, dec = 1;
        if (node->left) {
            auto [li, ld] = dfs(node->left);
            if (node->left->val == node->val + 1) inc = max(inc, li + 1);
            else if (node->left->val == node->val - 1) dec = max(dec, ld + 1);
        }
        if (node->right) {
            auto [ri, rd] = dfs(node->right);
            if (node->right->val == node->val + 1) inc = max(inc, ri + 1);
            else if (node->right->val == node->val - 1) dec = max(dec, rd + 1);
        }
        best = max(best, inc + dec - 1);
        return {inc, dec};
    }

public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return best;
    }
};
