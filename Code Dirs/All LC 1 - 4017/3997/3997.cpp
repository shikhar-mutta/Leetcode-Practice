// Link: https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/description/

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

// Added
// TC: O(n)  SC: O(h)
// Approach: post-order DFS returning the max value in each subtree;
// a node is dominant if its value equals that max, counted on the way up.
class Solution {
    int ans = 0;
    int dfs(TreeNode* node) {
        if (!node) return INT_MIN;
        int m = max({node->val, dfs(node->left), dfs(node->right)});
        if (m == node->val) ans++;
        return m;
    }
public:
    int countDominantNodes(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
