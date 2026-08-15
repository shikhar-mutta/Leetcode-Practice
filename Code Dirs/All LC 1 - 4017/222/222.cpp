// Link: https://leetcode.com/problems/count-complete-tree-nodes/description/

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

// TC: O(log^2 n)  SC: O(log n) recursion
// Approach: measure left-height and right-height by walking all-left / all-right; if equal the
// subtree is perfect (2^h - 1 nodes), else recurse into both children
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = 0, rh = 0;
        for (TreeNode* p = root; p; p = p->left) lh++;
        for (TreeNode* p = root; p; p = p->right) rh++;
        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
