// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

// TC: O(n)  SC: O(n)
// Approach: recursive; each node returns the best single-branch extension upward (clamped at 0), while
// updating a global best using both branches (a "through-node" path) at every node
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        function<int(TreeNode*)> gain = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int left = max(gain(node->left), 0);
            int right = max(gain(node->right), 0);
            best = max(best, node->val + left + right);
            return node->val + max(left, right);
        };
        gain(root);
        return best;
    }
};
