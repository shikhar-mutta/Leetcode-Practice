// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
// Approach: last postorder element is the root; find it in inorder (hash map) to split subtree ranges,
// recurse right-to-left with a shared postorder index decreasing across calls
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> pos;
        for (int i = 0; i < (int)inorder.size(); i++) pos[inorder[i]] = i;
        int postIdx = postorder.size() - 1;
        function<TreeNode*(int,int)> build = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) return nullptr;
            int rootVal = postorder[postIdx--];
            TreeNode* node = new TreeNode(rootVal);
            int mid = pos[rootVal];
            node->right = build(mid + 1, hi);
            node->left = build(lo, mid - 1);
            return node;
        };
        return build(0, inorder.size() - 1);
    }
};
