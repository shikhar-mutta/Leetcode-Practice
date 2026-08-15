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

class Solution {
    int leftCount = 0, rightCount = 0;
    int count(TreeNode* node, int x, int& target) {
        if (!node) return 0;
        int l = count(node->left, x, target);
        int r = count(node->right, x, target);
        if (node->val == x) { leftCount = l; rightCount = r; }
        return l + r + 1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x, x);
        int parentCount = n - leftCount - rightCount - 1;
        int best = max({leftCount, rightCount, parentCount});
        return best > n - best;
    }
};
