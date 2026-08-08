// Link: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return nullptr;
        if (original == target) return cloned;
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
