// Link: https://leetcode.com/problems/find-bottom-left-tree-value/description/

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
// Approach: BFS level order, remember the first node's value at each level;
// the last level's first value is the answer
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int result = root->val;
        while (!q.empty()) {
            int sz = q.size();
            result = q.front()->val;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};
