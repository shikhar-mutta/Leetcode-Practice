// Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int best = 0;

    void dfs(TreeNode* node, bool goingLeft, int len) {
        if (!node) return;
        best = max(best, len);
        if (goingLeft) {
            dfs(node->left, false, len + 1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->right, true, len + 1);
            dfs(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, false, 1);
        dfs(root->right, true, 1);
        return best;
    }
};
