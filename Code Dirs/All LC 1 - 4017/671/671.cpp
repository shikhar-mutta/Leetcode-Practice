// Link: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

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

// TC: O(n) SC: O(h)
// Approach: root is always the minimum (given tree property). DFS looking for the smallest value strictly greater than root->val; prune subtrees whose value equals root's min (since further descendants can't be smaller than that subtree's min in this structure... actually just track min second value directly via DFS, skipping nodes equal to root val is unnecessary, just compare).
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long long best = LLONG_MAX;
        dfs(root, root->val, best);
        return best == LLONG_MAX ? -1 : (int)best;
    }
    void dfs(TreeNode* node, int rootVal, long long& best) {
        if (!node) return;
        if (node->val > rootVal) {
            best = min(best, (long long)node->val);
            return; // subtree min is node->val (BST-like structure), no need to go deeper for smaller second-min
        }
        dfs(node->left, rootVal, best);
        dfs(node->right, rootVal, best);
    }
};
