// Link: https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/

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

// TC: O(n)  SC: O(h)
// Approach: in-order traversal linking each node to the previously visited
// one (left=prev, prev->right=cur); finally connect head and tail into a circle
class Solution {
    TreeNode* first = nullptr;
    TreeNode* last = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (last) {
            last->right = node;
            node->left = last;
        } else {
            first = node;
        }
        last = node;
        inorder(node->right);
    }

public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (!root) return nullptr;
        inorder(root);
        first->left = last;
        last->right = first;
        return first;
    }
};
