// Link: https://leetcode.com/problems/two-sum-bsts/description/

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
    void collect(TreeNode* node, unordered_set<int>& vals) {
        if (!node) return;
        vals.insert(node->val);
        collect(node->left, vals);
        collect(node->right, vals);
    }
    bool find(TreeNode* node, unordered_set<int>& vals, int target) {
        if (!node) return false;
        if (vals.count(target - node->val)) return true;
        return find(node->left, vals, target) || find(node->right, vals, target);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> vals;
        collect(root1, vals);
        return find(root2, vals, target);
    }
};
