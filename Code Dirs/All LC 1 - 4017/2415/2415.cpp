// Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<TreeNode*>> levels;
        levels.push_back({root});
        while (levels.back()[0]->left) {
            vector<TreeNode*> next;
            for (auto node : levels.back()) {
                next.push_back(node->left);
                next.push_back(node->right);
            }
            levels.push_back(next);
        }
        for (int d = 1; d < (int)levels.size(); d += 2) {
            auto &lvl = levels[d];
            int lo = 0, hi = lvl.size() - 1;
            while (lo < hi) {
                swap(lvl[lo]->val, lvl[hi]->val);
                lo++; hi--;
            }
        }
        return root;
    }
};
