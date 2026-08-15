// Link: https://leetcode.com/problems/binary-tree-tilt/description/

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
// Approach: postorder returning subtree sum, accumulate |leftSum-rightSum|
// at every node
class Solution {
    int totalTilt = 0;

    int sumTree(TreeNode* node) {
        if (!node) return 0;
        int l = sumTree(node->left);
        int r = sumTree(node->right);
        totalTilt += abs(l - r);
        return l + r + node->val;
    }

public:
    int findTilt(TreeNode* root) {
        sumTree(root);
        return totalTilt;
    }
};
