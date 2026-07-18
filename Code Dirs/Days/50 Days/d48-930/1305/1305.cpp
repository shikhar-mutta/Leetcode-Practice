// Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

#include <bits/stdc++.h>
using namespace std;

#ifndef TREENODE_DEFINED
#define TREENODE_DEFINED
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

// TC: O(n + m) where n and m are the number of nodes in the two trees. We traverse both trees once to get their elements in sorted order, and then we merge the two sorted lists.
// SC: O(n + m) for storing the elements of both trees in the output vector
// Approach:
//  1. Perform an inorder traversal of both binary search trees to get their elements in sorted order.
//  2. Merge the two sorted lists into a single sorted list.
class Solution
{
public:
    void inorder(TreeNode *node, vector<int> &out)
    {
        if (!node)
            return;
        inorder(node->left, out);
        out.push_back(node->val);
        inorder(node->right, out);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);
        vector<int> res(a.size() + b.size());
        merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
        return res;
    }
};
