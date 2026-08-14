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

class Solution {
    unordered_map<TreeNode*, int> ht;
    unordered_map<int, int> answer;

    int computeHeight(TreeNode* node) {
        if (!node) return -1;
        int h = 1 + max(computeHeight(node->left), computeHeight(node->right));
        ht[node] = h;
        return h;
    }

    void dfs(TreeNode* node, int depth, int maxAbove) {
        if (!node) return;
        answer[node->val] = max(0, max(depth - 1, maxAbove));
        int leftReach = node->left ? depth + 1 + ht[node->left] : -1;
        int rightReach = node->right ? depth + 1 + ht[node->right] : -1;
        dfs(node->left, depth + 1, max(maxAbove, rightReach));
        dfs(node->right, depth + 1, max(maxAbove, leftReach));
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        computeHeight(root);
        dfs(root, 0, -1);
        vector<int> ans;
        for (int q : queries) ans.push_back(answer[q]);
        return ans;
    }
};
