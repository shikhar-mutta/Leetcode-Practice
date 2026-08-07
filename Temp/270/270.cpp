// Link: https://leetcode.com/problems/closest-binary-search-tree-value/description/

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

// TC: O(h)  SC: O(1)
// Approach: walk down the BST, updating the closest value seen at each node, guided by comparing target
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        TreeNode* node = root;
        while (node) {
            if (abs(node->val - target) < abs(closest - target)) closest = node->val;
            node = target < node->val ? node->left : node->right;
        }
        return closest;
    }
};
