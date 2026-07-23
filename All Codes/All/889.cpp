// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

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
//   Approach:
//   1. The first element of the preorder traversal is the root of the tree.
//   2. The second element of the preorder traversal is the root of the left subtree.
//   3. Find the index of the left subtree root in the postorder traversal to determine the size of the left subtree.
//   4. Recursively build the left and right subtrees using the corresponding segments of the preorder and postorder traversals.
//   5. Return the constructed tree
class Solution
{
public:
    TreeNode *build(vector<int> &pre, int preStart, int preEnd,
                    vector<int> &post, int postStart, int postEnd)
    {
        if (preStart > preEnd)
            return nullptr;
        TreeNode *root = new TreeNode(pre[preStart]);
        if (preStart == preEnd)
            return root;

        int leftRootVal = pre[preStart + 1];
        int leftSize = 0;
        while (post[postStart + leftSize] != leftRootVal)
            leftSize++;
        leftSize++;

        root->left = build(pre, preStart + 1, preStart + leftSize,
                           post, postStart, postStart + leftSize - 1);
        root->right = build(pre, preStart + leftSize + 1, preEnd,
                            post, postStart + leftSize, postEnd - 1);
        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};
