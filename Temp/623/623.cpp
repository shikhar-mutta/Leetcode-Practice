// Link: https://leetcode.com/problems/add-one-row-to-tree/description/

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
// Approach: recursive DFS tracking current depth; at depth == d-1, insert new nodes as new left/right children wrapping the existing subtrees; depth==1 special case wraps the whole root.
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        insert(root, val, depth, 1);
        return root;
    }
    void insert(TreeNode* node, int val, int depth, int curDepth) {
        if (!node) return;
        if (curDepth == depth - 1) {
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = node->left;
            node->left = newLeft;
            TreeNode* newRight = new TreeNode(val);
            newRight->right = node->right;
            node->right = newRight;
        } else {
            insert(node->left, val, depth, curDepth+1);
            insert(node->right, val, depth, curDepth+1);
        }
    }
};
