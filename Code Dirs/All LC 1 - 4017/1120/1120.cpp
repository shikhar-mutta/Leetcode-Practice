// Link: https://leetcode.com/problems/maximum-average-subtree/description/

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
    double best = 0;
    pair<long long,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        long long sum = l.first + r.first + node->val;
        int cnt = l.second + r.second + 1;
        best = max(best, (double)sum / cnt);
        return {sum, cnt};
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return best;
    }
};
