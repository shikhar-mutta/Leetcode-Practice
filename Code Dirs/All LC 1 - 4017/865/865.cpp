// Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

private:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        if (l.first == r.first) return {l.first + 1, node};
        return l.first > r.first ? make_pair(l.first + 1, l.second) : make_pair(r.first + 1, r.second);
    }
};
