// Link: https://leetcode.com/problems/leaf-similar-trees/description/

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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        collectLeaves(root1, l1);
        collectLeaves(root2, l2);
        return l1 == l2;
    }

private:
    void collectLeaves(TreeNode* node, vector<int>& leaves) {
        if (!node) return;
        if (!node->left && !node->right) { leaves.push_back(node->val); return; }
        collectLeaves(node->left, leaves);
        collectLeaves(node->right, leaves);
    }
};
