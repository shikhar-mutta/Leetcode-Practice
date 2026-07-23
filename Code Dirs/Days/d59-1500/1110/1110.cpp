// Link: https://leetcode.com/problems/delete-nodes-and-return-forest/description/

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

// TC: O(n) where n is the number of nodes in the tree
// SC: O(n) where n is the number of nodes in the tree
// Approach:
//  1. We will use a recursive helper function to traverse the tree and delete the nodes that are present in the to_delete set.
//  2. If a node is deleted, we will add its children to the answer vector if they are not NULL.
//  3. Finally, we will return the answer vector containing the roots of the remaining trees in the forest.
class Solution
{
public:
    vector<TreeNode *> ans;

    TreeNode *helper(TreeNode *root, unordered_set<int> &st)
    {
        if (root == NULL)
        {
            return NULL;
        }

        TreeNode *Left = helper(root->left, st);
        TreeNode *Right = helper(root->right, st);

        if (st.count(root->val))
        {
            if (Left)
                ans.push_back(Left);
            if (Right)
                ans.push_back(Right);
            return NULL;
        }

        root->left = Left;
        root->right = Right;

        return root;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> st;

        for (int d : to_delete)
        {
            st.insert(d);
        }

        TreeNode *node = helper(root, st);
        if (node)
        {
            ans.push_back(node);
        }

        return ans;
    }
};