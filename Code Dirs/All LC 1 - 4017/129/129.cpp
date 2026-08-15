// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
// Approach: DFS accumulating cur*10+val down each path, sum values reaching leaf nodes
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int total = 0;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* node, int cur) {
            if (!node) return;
            cur = cur * 10 + node->val;
            if (!node->left && !node->right) { total += cur; return; }
            dfs(node->left, cur);
            dfs(node->right, cur);
        };
        dfs(root, 0);
        return total;
    }
};
