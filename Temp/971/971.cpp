// Link: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/

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
    int idx = 0;
    bool failed = false;
    vector<int> flips;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root, voyage);
        if (failed) return {-1};
        return flips;
    }

private:
    void dfs(TreeNode* node, vector<int>& voyage) {
        if (!node || failed) return;
        if (node->val != voyage[idx]) { failed = true; return; }
        idx++;
        if (node->left && idx < (int)voyage.size() && node->left->val != voyage[idx]) {
            flips.push_back(node->val);
            dfs(node->right, voyage);
            dfs(node->left, voyage);
        } else {
            dfs(node->left, voyage);
            dfs(node->right, voyage);
        }
    }
};
