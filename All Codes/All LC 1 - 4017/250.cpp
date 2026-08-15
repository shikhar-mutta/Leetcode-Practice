// Link: https://leetcode.com/problems/count-univalue-subtrees/description/

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
// Approach: post-order DFS; a subtree is univalue iff both children are univalue subtrees and
// share the node's value (missing children trivially satisfy this)
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
            if (!node) return true;
            bool leftOk = dfs(node->left);
            bool rightOk = dfs(node->right);
            bool isUnival = leftOk && rightOk;
            if (isUnival && node->left && node->left->val != node->val) isUnival = false;
            if (isUnival && node->right && node->right->val != node->val) isUnival = false;
            if (isUnival) count++;
            return isUnival;
        };
        dfs(root);
        return count;
    }
};
