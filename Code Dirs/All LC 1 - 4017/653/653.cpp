// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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

// TC: O(n) SC: O(n)
// Approach: DFS collecting visited values in a set; at each node check if k - val already seen.
class Solution {
    unordered_set<int> seen;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
