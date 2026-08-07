// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
// Approach: first preorder element is the root; find it in inorder (hash map) to split left/right subtree ranges,
// recurse with a shared preorder index advancing across calls
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> pos;
        for (int i = 0; i < (int)inorder.size(); i++) pos[inorder[i]] = i;
        int preIdx = 0;
        function<TreeNode*(int,int)> build = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) return nullptr;
            int rootVal = preorder[preIdx++];
            TreeNode* node = new TreeNode(rootVal);
            int mid = pos[rootVal];
            node->left = build(lo, mid - 1);
            node->right = build(mid + 1, hi);
            return node;
        };
        return build(0, inorder.size() - 1);
    }
};
