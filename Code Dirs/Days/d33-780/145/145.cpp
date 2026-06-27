// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    // TC: O(n), SC: O(n). Iterative solution.
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->left)
                st.push(node->left);
            if (node->right)
                st.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
