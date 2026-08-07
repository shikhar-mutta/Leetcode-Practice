// Link: https://leetcode.com/problems/diameter-of-binary-tree/description/

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
// Approach: postorder computing height, track max (leftHeight+rightHeight)
// as the diameter candidate at each node
class Solution {
    int best = 0;

    int height(TreeNode* node) {
        if (!node) return 0;
        int l = height(node->left);
        int r = height(node->right);
        best = max(best, l + r);
        return 1 + max(l, r);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return best;
    }
};
