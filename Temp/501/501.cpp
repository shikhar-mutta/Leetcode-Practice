// Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

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

// TC: O(n)  SC: O(1) extra (O(h) recursion)
// Approach: inorder traversal gives sorted order for a BST; track running
// streak length vs current max, collecting values that tie the max
class Solution {
    vector<int> modes;
    int curVal = 0, curCount = 0, maxCount = 0;
    bool first = true;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);

        if (!first && node->val == curVal) curCount++;
        else curCount = 1;
        curVal = node->val;
        first = false;

        if (curCount > maxCount) {
            maxCount = curCount;
            modes = {curVal};
        } else if (curCount == maxCount) {
            modes.push_back(curVal);
        }

        inorder(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};
