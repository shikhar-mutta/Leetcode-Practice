// Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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
// Approach: BFS level order, track max value per level
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int best = INT_MIN;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                best = max(best, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(best);
        }
        return res;
    }
};
