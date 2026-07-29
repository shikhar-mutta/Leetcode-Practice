// Link: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/

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

// TC: O(N), SC: O(N)
// Approach: compute depth[node] and subtreeMaxDepth[node] (deepest node's depth within subtree).
// Then propagate top-down "best depth reachable outside this subtree" from parent to children,
// using the sibling's subtreeMaxDepth when there are two children. ans[node] = that passed value.
class Solution {
public:
    unordered_map<int,int> depth, subMax, ans;

    int computeDepth(TreeNode* node, int d) {
        if (!node) return -1;
        depth[node->val] = d;
        int mx = d;
        mx = max(mx, computeDepth(node->left, d+1));
        mx = max(mx, computeDepth(node->right, d+1));
        subMax[node->val] = mx;
        return mx;
    }

    void propagate(TreeNode* node, int passedDown) {
        if (!node) return;
        ans[node->val] = passedDown;
        int leftMax = node->left ? subMax[node->left->val] : -1;
        int rightMax = node->right ? subMax[node->right->val] : -1;
        propagate(node->left, max(passedDown, rightMax));
        propagate(node->right, max(passedDown, leftMax));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        computeDepth(root, 0);
        propagate(root, 0);
        vector<int> result;
        for (int q : queries) result.push_back(ans[q]);
        return result;
    }
};
