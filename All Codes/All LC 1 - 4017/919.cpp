// Link: https://leetcode.com/problems/complete-binary-tree-inserter/description/

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

// TC: O(n) for constructor, O(1) for insert and get_root
// SC: O(n) for constructor, O(1) for insert and get_root
// Approach:
//  1. In the constructor, we perform a level order traversal of the tree and store all the nodes in a vector.
//  2. For the insert operation, we find the parent of the new node using the formula (n-1)/2, where n is the current number of nodes in the tree.
//  3. We then check if the parent has a left child. If not, we insert the new node as the left child. Otherwise, we insert it as the right child.
//  4. Finally, we add the new node to the vector of nodes and return the value of the parent node.
class CBTInserter
{
    vector<TreeNode *> nodes;
    TreeNode *root;

public:
    CBTInserter(TreeNode *root)
    {
        this->root = root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            nodes.push_back(cur);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

    int insert(int val)
    {
        TreeNode *node = new TreeNode(val);
        int n = nodes.size();
        TreeNode *parent = nodes[(n - 1) / 2];
        if (!parent->left)
            parent->left = node;
        else
            parent->right = node;
        nodes.push_back(node);
        return parent->val;
    }

    TreeNode *get_root()
    {
        return root;
    }
};
