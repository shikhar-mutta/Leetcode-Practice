// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
// Approach: BFS assigning each node a positional index (as if the tree were a complete binary tree); width of a level is last index - first index + 1. Use long long and rebase indices per level to avoid overflow.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long best = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            long long first = q.front().second, last = first;
            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front(); q.pop();
                last = idx;
                if (node->left) q.push({node->left, 2*(idx-first)});
                if (node->right) q.push({node->right, 2*(idx-first)+1});
            }
            best = max(best, last - first + 1);
        }
        return (int)best;
    }
};
