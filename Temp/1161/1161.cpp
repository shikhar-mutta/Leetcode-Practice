// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, bestLevel = 1, bestSum = INT_MIN;
        while (!q.empty()) {
            level++;
            int sz = q.size();
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > bestSum) { bestSum = sum; bestLevel = level; }
        }
        return bestLevel;
    }
};
