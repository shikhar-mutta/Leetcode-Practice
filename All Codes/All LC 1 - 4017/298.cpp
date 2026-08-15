// Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/

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
// Approach: DFS passing down the running consecutive length from parent;
// reset to 1 if current value doesn't continue parent's sequence
class Solution {
    int best = 0;

    void dfs(TreeNode* node, TreeNode* parent, int len) {
        if (!node) return;
        if (parent && node->val == parent->val + 1) len++;
        else len = 1;
        best = max(best, len);
        dfs(node->left, node, len);
        dfs(node->right, node, len);
    }

public:
    int longestConsecutive(TreeNode* root) {
        dfs(root, nullptr, 0);
        return best;
    }
};
