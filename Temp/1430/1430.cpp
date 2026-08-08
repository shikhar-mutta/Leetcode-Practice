// Link: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool dfs(TreeNode* node, vector<int>& arr, int idx) {
        if (!node || idx >= (int)arr.size() || node->val != arr[idx]) return false;
        if (idx == (int)arr.size() - 1) return !node->left && !node->right;
        return dfs(node->left, arr, idx + 1) || dfs(node->right, arr, idx + 1);
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
};
