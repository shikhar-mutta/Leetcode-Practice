// Link: https://leetcode.com/problems/binary-search-tree-iterator/description/

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

// TC: O(1). SC: O(h).
class BSTIterator
{
private:
    stack<TreeNode *> st;

private:
    void helper(TreeNode *node)
    {
        // Push all the left children of the node onto the stack
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root) { helper(root); }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        // if has right child, push them to the stack
        if (node->right)
            helper(node->right);
        return node->val;
    }

    bool hasNext() { return st.size() != 0; }
};
