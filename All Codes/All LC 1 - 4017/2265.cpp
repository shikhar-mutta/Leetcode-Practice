// Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/

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
    int count = 0;
public:
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [lsum, lcnt] = dfs(node->left);
        auto [rsum, rcnt] = dfs(node->right);
        int sum = lsum + rsum + node->val;
        int cnt = lcnt + rcnt + 1;
        if (sum / cnt == node->val) count++;
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};
