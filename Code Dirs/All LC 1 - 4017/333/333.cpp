// Link: https://leetcode.com/problems/largest-bst-subtree/description/

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
// Approach: postorder returning (isBST, size, min, max) for each subtree;
// a node forms a BST iff both children are BSTs and its value fits between them
class Solution {
    int best = 0;

    tuple<bool,int,int,int> dfs(TreeNode* node) {
        if (!node) return {true, 0, INT_MAX, INT_MIN};
        auto [lBST, lSize, lMin, lMax] = dfs(node->left);
        auto [rBST, rSize, rMin, rMax] = dfs(node->right);
        if (lBST && rBST && (!node->left || lMax < node->val) && (!node->right || node->val < rMin)) {
            int size = lSize + rSize + 1;
            best = max(best, size);
            int mn = node->left ? lMin : node->val;
            int mx = node->right ? rMax : node->val;
            return {true, size, mn, mx};
        }
        return {false, 0, 0, 0};
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return best;
    }
};
