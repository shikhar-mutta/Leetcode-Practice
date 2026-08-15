// Link: https://leetcode.com/problems/house-robber-iii/description/

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
// Approach: postorder returning (best if this node robbed, best if not),
// combine children's "not robbed" for robbed case, max of either for not-robbed
class Solution {
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [lRob, lSkip] = dfs(node->left);
        auto [rRob, rSkip] = dfs(node->right);
        int robbed = node->val + lSkip + rSkip;
        int skipped = max(lRob, lSkip) + max(rRob, rSkip);
        return {robbed, skipped};
    }

public:
    int rob(TreeNode* root) {
        auto [robbed, skipped] = dfs(root);
        return max(robbed, skipped);
    }
};
