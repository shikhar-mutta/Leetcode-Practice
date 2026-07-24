// Link: https://leetcode.com/problems/balance-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n), SC: O(n)
//  Approach:
//   1. We perform an inorder traversal of the given BST to collect all the nodes in a sorted order and store them in the nodes vector.
//   2. We then use a recursive function build to construct a balanced BST from the sorted nodes. The function takes two indices, l and r, representing the current range of nodes to consider. We find the middle index mid and make the node at that index the root of the current subtree. We recursively build the left and right subtrees using the left and right halves of the current range.
//   3. Finally, we return the root of the balanced BST constructed from the sorted nodes.
class Solution
{
    vector<TreeNode *> nodes;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
    TreeNode *build(int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *root = nodes[mid];
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};